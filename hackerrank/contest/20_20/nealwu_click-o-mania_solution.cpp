<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<!DOCTYPE html PUBLIC "" ""><HTML><HEAD><META content="IE=10.000" 
http-equiv="X-UA-Compatible">

<META http-equiv="Content-Type" content="text/html; charset=utf-8"></HEAD>
<BODY>
<PRE>#define NDEBUG
#include &lt;cstdio&gt;
#include &lt;cstring&gt;
#include &lt;cassert&gt;
#include &lt;vector&gt;
#include &lt;map&gt;
#include &lt;set&gt;
#include &lt;algorithm&gt;
using namespace std;

const int HEIGHT = 20, WIDTH = 10, KEEP = 250;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
const int HASH_MULT = 783820769;

struct grid
{
    long long column[WIDTH];
    int done[WIDTH];
    int first_move[2];

    grid()
    {
        first_move[0] = first_move[1] = -1;
    }

    int get(int r, int c)
    {
        assert(valid(r, c));
        return (column[c] &gt;&gt; (3 * r)) &amp; 7;
    }

    void set(int r, int c, int color)
    {
        assert(valid(r, c));
        assert(0 &lt;= color &amp;&amp; color &lt; 8);
        column[c] &amp;= -1LL ^ (7LL &lt;&lt; (3 * r));
        column[c] ^= (long long) color &lt;&lt; (3 * r);
    }

    bool get_done(int r, int c)
    {
        assert(valid(r, c));
        return (done[c] &gt;&gt; r) &amp; 1;
    }

    void set_done(int r, int c, bool value)
    {
        assert(valid(r, c));
        done[c] &amp;= -1 ^ (1 &lt;&lt; r);
        done[c] ^= ((int) value) &lt;&lt; r;
    }

    bool valid(int r, int c)
    {
        return r &gt;= 0 &amp;&amp; r &lt; HEIGHT &amp;&amp; c &gt;= 0 &amp;&amp; c &lt; WIDTH;
    }

    bool is_singleton(int r, int c)
    {
        assert(valid(r, c));
        int color = get(r, c);

        if (color == 0)
            return false;

        for (int d = 0; d &lt; 4; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];

            if (valid(nr, nc) &amp;&amp; get(nr, nc) == color)
                return false;
        }

        return true;
    }

    int singletons()
    {
        // TODO: optimize this. Perhaps do operations in parallel?
        int singles = 0;

        for (int c = 0; c &lt; WIDTH; c++)
            for (int r = 0; r &lt; HEIGHT; r++)
                if (is_singleton(r, c))
                    singles++;

        return singles;
    }

    void pop(int r, int c, int color, bool set_zero = true)
    {
        assert(valid(r, c));
        assert(color != 0);
        // Mark as zero and then check for equal neighbors
        if (set_zero)
            set(r, c, 0);

        set_done(r, c, true);

        for (int d = 0; d &lt; 4; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];

            if (valid(nr, nc) &amp;&amp; get(nr, nc) == color &amp;&amp; !get_done(nr, nc))
                pop(nr, nc, color, set_zero);
        }
    }

    void mark(int r, int c)
    {
        assert(valid(r, c));
        int color = get(r, c);
        assert(color != 0);
        pop(r, c, color, false);
    }

    void click(int r, int c)
    {
        assert(valid(r, c));
        // Should not already be done
        assert(!get_done(r, c));
        int color = get(r, c);
        assert(color != 0);
        assert(!is_singleton(r, c));
        pop(r, c, color);
        squish();

        // Undo all done
        for (int i = 0; i &lt; WIDTH; i++)
            done[i] = 0;

        if (first_move[0] == -1)
        {
            first_move[0] = r;
            first_move[1] = c;
        }
    }

    void squish()
    {
        for (int c = 0; c &lt; WIDTH; c++)
        {
            int move = HEIGHT - 1;

            for (int r = HEIGHT - 1; r &gt;= 0; r--)
            {
                int color = get(r, c);

                if (color != 0)
                {
                    set(r, c, get(move, c));
                    set(move, c, color);
                    move--;
                }
            }
        }

        int move = 0;

        for (int c = 0; c &lt; WIDTH; c++)
            if (column[c] != 0)
                swap(column[move++], column[c]);
    }

    long long hash()
    {
        long long h = 0;

        for (int c = 0; c &lt; WIDTH; c++)
            h = HASH_MULT * h + column[c];

        return h;
    }

    bool operator &lt; (const grid &amp;other) const
    {
        // Something random because it doesn't matter
        return first_move[0] &lt; other.first_move[0];
    }

    void print()
    {
        for (int r = 0; r &lt; HEIGHT; r++)
        {
            for (int c = 0; c &lt; WIDTH; c++)
                putchar(get(r, c) + '0');

            putchar('\n');
        }

        printf("%d %d\n", first_move[0], first_move[1]);
    }
};

int H, W, K;
char cgrid[HEIGHT][WIDTH + 1];
map&lt;char, int&gt; color_to_number;
grid game;
pair&lt;int, grid&gt; best_game;

int main()
{
    scanf("%d %d %d", &amp;H, &amp;W, &amp;K);
    assert(H == HEIGHT &amp;&amp; W == WIDTH);
    int C = 0;
    color_to_number['.'] = color_to_number['-'] = C++;

    for (int r = 0; r &lt; HEIGHT; r++)
    {
        scanf("%s", cgrid[r]);

        for (int c = 0; c &lt; WIDTH; c++)
        {
            if (color_to_number.find(cgrid[r][c]) == color_to_number.end())
                color_to_number[cgrid[r][c]] = C++;

            game.set(r, c, color_to_number[cgrid[r][c]]);
        }
    }

    assert(C &lt;= K + 1);
    assert(C &lt;= 8);

    vector&lt;pair&lt;int, grid&gt; &gt; possible;
    best_game = make_pair(game.singletons(), game);
    possible.push_back(best_game);

    set&lt;long long&gt; hashes;
    hashes.insert(game.hash());

    while (!possible.empty())
    {
        assert((int) possible.size() &lt;= KEEP);

        for (int i = 0; i &lt; (int) possible.size(); i++)
            if (possible[i].first &lt;= best_game.first)
                best_game = possible[i];

        vector&lt;pair&lt;int, grid&gt; &gt; npossible;

        for (int i = 0; i &lt; (int) possible.size(); i++)
        {
            grid current = possible[i].second;

            for (int c = 0; c &lt; WIDTH; c++)
                for (int r = 0; r &lt; HEIGHT; r++)
                    if (current.get(r, c) != 0 &amp;&amp; !current.get_done(r, c) &amp;&amp; !current.is_singleton(r, c))
                    {
                        grid candidate = current;
                        candidate.click(r, c);

                        if (hashes.insert(candidate.hash()).second)
                            npossible.push_back(make_pair(candidate.singletons(), candidate));

                        current.mark(r, c);
                    }
        }

        if ((int) npossible.size() &gt; KEEP)
        {
            nth_element(npossible.begin(), npossible.begin() + KEEP, npossible.end());
            npossible.resize(KEEP);
        }

        possible = npossible;
    }

    //printf("%d\n", best_game.first);
    assert(best_game.second.first_move[0] != -1);
    printf("%d %d\n", best_game.second.first_move[0], best_game.second.first_move[1]);
    return 0;
}</PRE></BODY></HTML>

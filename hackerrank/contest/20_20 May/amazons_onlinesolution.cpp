/*
 * Amazons is a 2 player abstract strategy games that takes place on a chess board of size 10x10. Each player has 4 amazons (represented as Queens of Chess) as shown in the board below.

amazons-board

A player is either white or black with white moving first. Each move consists of 2 parts: one of the current player¡¯s amazon is moved from its current position to a new empty square in a straight line (orthogonally or diagonally) not crossing any non-empty square (similar to a Queen¡¯s movement in Chess). The second part consists of the amazon shooting an arrow from its new square to an empty square in a straight line (orthogonally or diagonally) not crossing any non-empty square. The amazon can also shoot an arrow in the direction it traveled. The last player to make a move wins.

Input Format

The board is indexed ¡®a¡¯ (ascii value 97) to ¡®j¡¯ (ascii value 106) from left to right and ¡®0¡¯ ( ascii value 48 ) to ¡®9¡¯ (ascii value 57) from bottom to top as shown in the figure above. White amazons are represented by the character ¡®W¡¯ (ascii value 87) and the Black amazons are represented by the character ¡®B¡¯ ( ascii value 66). Empty squares are represented by ¡®-¡® (ascii value 45) and the squares where arrows land are represented by ¡®.¡¯ (ascii value 46).

The first line of the input is either ¡®W¡¯ or ¡®B¡¯ representing the 1st or the 2nd player. The 2nd line has 10 10 which is the row/column size of the board. 10 lines follow each line having 10 characters representing a row in the board.

Output Format

Output the position of the amazon you wish to move followed by the new position of the amazon and finally print the position of the square where the arrow should land. The output is written as

<char><num> <char><num> <char><num>
Sample Input

W
10 10
B----.B---
....-....-
..W.---B..
W..-----.-
..--------
-.------..
--B----..W
---.--...-
------.W--
-----...--
Sample Output

h1 j1 i1
Explanation

The current player is white. He moves one of his amazons positioned at h1 to j1 and shoots an arrow that lands at i1. The new configuration of the board is

B----.B---
....-....-
..W.---B..
W..-----.-
..--------
-.------..
--B----..W
---.--...-
------.-.W
-----...--
Task

Complete the function next_move that takes a character player and a 2-D array of character board as input and prints the output.
 *
 *
 */

#include <iostream>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

const double INF = numeric_limits<double>::infinity();

struct int128_t {
  uint64_t a, b;

  int128_t() {}

  int128_t(uint64_t a, uint64_t b): a(a), b(b) {}

  int128_t operator~() {
    return int128_t(~a, ~b);
  }

  int128_t operator&(const int128_t& o) {
    return int128_t(a & o.a, b & o.b);
  }

  int128_t operator|(const int128_t& o) {
    return int128_t(a | o.a, b | o.b);
  }

  int128_t operator^(const int128_t& o) {
    return int128_t(a ^ o.a, b ^ o.b);
  }

  int128_t operator<<(int shift) {
    if (shift < 0) {
      return int128_t((a >> (-shift)) | (b << (shift + 64)), b >> (-shift));
    } else {
      return int128_t(a << shift, (b << shift) | (a >> (64 - shift)));
    }
  }

  int128_t& operator&=(const int128_t& o) {
    a &= o.a;
    b &= o.b;
    return *this;
  }

  int128_t& operator|=(const int128_t& o) {
    a |= o.a;
    b |= o.b;
    return *this;
  }

  int128_t& operator^=(const int128_t& o) {
    a ^= o.a;
    b ^= o.b;
    return *this;
  }

  int128_t& setBit(int i, bool bit) {
    if (bit) {
      return setBit(i);
    } else {
      return resetBit(i);
    }
  }

  int128_t& setBit(int i) {
    if (i < 64) {
      a |= 1ULL << i;
    } else {
      b |= 1ULL << (i - 64);
    }
    return *this;
  }

  int128_t& resetBit(int i) {
    if (i < 64) {
      a &= ~(1ULL << i);
    } else {
      b &= ~(1ULL << (i - 64));
    }
    return *this;
  }

  bool getBit(int i) const {
    if (i < 0 || i >= 128) {
      return false;
    }
    if (i < 64) {
      return (a & (1ULL << i)) != 0;
    } else {
      return (b & (1ULL << (i - 64))) != 0;
    }
  }

  bool operator==(int128_t& o) {
    return a == o.a && b == o.b;
  }

  int bitcount() {
    return __builtin_popcountll(a) + __builtin_popcountll(b);
  }
};

uint64_t magic0[128], magic1[128], magic2[128];
int moves[] = {-13, -12, -11, -1, 1, 11, 12, 13};

struct Pos {
  int128_t f;
  char amazons1[4], amazons2[4];
  uint64_t hash;

  void initHash() {
    hash = 0;
    for (int i = 0; i < 128; ++i) {
      if (f.getBit(i)) {
        hash ^= magic0[i];
      }
    }
    for (char a : amazons1) {
      hash ^= magic1[a];
    }
    for (char a : amazons2) {
      hash ^= magic2[a];
    }
  }

  void move(int i, int to, int to2) {
    /*assert(f.getBit(to));
      assert(f.getBit(to2));*/
    hash ^= magic1[amazons1[i]];
    hash ^= magic1[to];
    amazons1[i] = to;
    hash ^= magic0[to2];
    f.resetBit(to2);
    for (int i = 0; i < 4; ++i) {
      hash ^= magic1[amazons1[i]] ^ magic2[amazons2[i]];
      swap(amazons1[i], amazons2[i]);
      hash ^= magic1[amazons1[i]] ^ magic2[amazons2[i]];
    }
    /*uint64_t hash0 = hash;
    initHash();
    assert(hash == hash0);*/
  }
};

int computeD1(int128_t* d, const int128_t& f, const char* a1, const char* a2) {
  int r = 0;
  d[0] = int128_t(0, 0);
  int128_t mask = f;
  for (int i = 0; i < 4; ++i) {
    mask.resetBit(a2[i]);
    d[0].setBit(a1[i]);
  }
  while (true) {
    r++;
    d[r] = d[r - 1];
    for (int m : moves) {
      int128_t tmp = d[r - 1];
      while (true) {
        int128_t tmp1 = (tmp | (tmp << m)) & mask;
        if (tmp == tmp1) {
          break;
        } else {
          tmp = tmp1;
        }
      }
      d[r] |= tmp;
    }
    if (d[r] == d[r - 1]) {
      break;
    }
  }
  return r;
}

int computeMobility(const int128_t& f, char a1, char depth, const char* a2) {
  int r = 0;
  int128_t d = int128_t(0, 0);
  d.setBit(a1);
  int128_t mask = f;
  for (int i = 0; i < 4; ++i) {
    mask.resetBit(a2[i]);
  }
  for (int it = 0; it < depth; ++it) {
    r++;
    int128_t dNew = d;
    for (int m : moves) {
      int128_t tmp = d;
      while (true) {
        int128_t tmp1 = (tmp | (tmp << m)) & mask;
        if (tmp == tmp1) {
          break;
        } else {
          tmp = tmp1;
        }
      }
      dNew |= tmp;
    }
    d = dNew;
  }
  return d.bitcount();
}

int computeD2(int128_t* d, const int128_t& f, const char* a1, const char* a2) {
  int r = 0;
  d[0] = int128_t(0, 0);
  int128_t mask = f;
  for (int i = 0; i < 4; ++i) {
    mask.resetBit(a2[i]);
    d[0].setBit(a1[i]);
  }
  while (true) {
    r++;
    d[r] = d[r - 1];
    for (int m : moves) {
      d[r] |= d[r - 1] << m;
    }
    d[r] &= mask;
    if (d[r] == d[r - 1]) {
      break;
    }
  }
  return r;
}

void print(ostream& s, const Pos& p, int128_t add) {
  int128_t a1(0, 0), a2(0, 0);
  for (char a : p.amazons1) {
    a1.setBit(a);
  }
  for (char a : p.amazons2) {
    a2.setBit(a);
  }
  s << "------------\n";
  for (int i = 0; i < 10; ++i) {
    string line = "|";
    for (int j = 0; j < 10; ++j) {
      int x = i * 12 + j + 1;
      if (add.getBit(x)) {
        line += '*';
      } else if (!p.f.getBit(x)) {
        line += '.';
      } else if (a1.getBit(x)) {
        line += 'W';
      } else if (a2.getBit(x)) {
        line += 'B';
      } else {
        line += ' ';
      }
    }
    line += '|';
    s << line << "\n";
  }
  s << "------------\n";
}

ostream& operator<<(ostream& s, Pos& p) {
  print(s, p, int128_t(0, 0));
  return s;
}

double evaluate(const Pos& pos) {
  int128_t d11[100];
  int128_t d21[100];
  int128_t d12[100];
  int128_t d22[100];
  int d11s = computeD1(d11, pos.f, pos.amazons1, pos.amazons2);
  int d21s = computeD2(d21, pos.f, pos.amazons1, pos.amazons2);
  int d12s = computeD1(d12, pos.f, pos.amazons2, pos.amazons1);
  int d22s = computeD2(d22, pos.f, pos.amazons2, pos.amazons1);
  double t1 = 0, c1 = 0;
  double p2 = 1.;
  for (int i = 1; i < d11s; ++i) {
    int128_t cur = d11[i] ^ d11[i - 1];
    t1 += (cur & ~d12[i]).bitcount();
    c1 += p2 * cur.bitcount();
    p2 *= 0.5;
  }
  p2 = 1.;
  for (int i = 1; i < d12s; ++i) {
    int128_t cur = d12[i] ^ d12[i - 1];
    t1 -= (cur & ~d11[i]).bitcount();
    c1 -= p2 * cur.bitcount();
    p2 *= 0.5;
  }
  double t2 = 0;
  for (int i = 1; i < d21s; ++i) {
    int128_t cur = d21[i] ^ d21[i - 1];
    t2 += (cur & ~d22[i]).bitcount();
  }
  for (int i = 1; i < d12s; ++i) {
    int128_t cur = d22[i] ^ d22[i - 1];
    t2 -= (cur & ~d21[i]).bitcount();
  }
  double m1 = d11[1].bitcount() - d12[1].bitcount();
  double m2 = d11[min(2, d11s - 1)].bitcount() - d12[min(2, d12s - 1)].bitcount();
  double w = (d11[min(3, d11s - 1)] & d12[min(3, d12s - 1)]).bitcount();
  /*double m3 = 0.;
  for (int i = 0; i < 4; ++i) {
    m3 -= 30. / computeMobility(pos.f, pos.amazons1[i], 2, pos.amazons2);
    m3 += 30. / computeMobility(pos.f, pos.amazons2[i], 2, pos.amazons1);
    }*/
  double val = (w / 100) * (0.5 * t2 + 0.3 * m1 + 0.4 * m2) + (1 - w / 100) * (0.5 * t1 + 0.7 * c1);
  //cerr << pos.hash << ": " << val << " t1=" << t1 << " c1=" << c1 << " t2=" << t2 << " m1=" << m1 << " m2=" << m2 << " w=" << w << "\n";
  return val;
}

struct Move {
  int fromi, to, to2;

  Move(): fromi(-1), to(-1), to2(-1) {};

  Move(int fromi, int to, int to2): fromi(fromi), to(to), to2(to2) {}
};

struct State {
  int depth = -1;
  double alpha = -INF, beta = INF;
  Move bestMove;
};

unordered_map<uint64_t, State> table;

clock_t t0 = clock();
int counter = 0;
Pos pos0;

string toCoords(int x) {
  char col = (x % 12 - 1) + 'a';
  char row = (9 - x / 12) + '0';
  string r = "";
  r += col;
  r += row;
  return r;
}

void done() {
  Move& bestMove = table[pos0.hash].bestMove;
  cerr << table[pos0.hash].depth << " " << table[pos0.hash].alpha << " " << table[pos0.hash].beta << "\n";
  cout << toCoords(pos0.amazons1[bestMove.fromi]) << " " << toCoords(bestMove.to) << " " << toCoords(bestMove.to2) << "\n";
  cerr << counter << "\n";
}

double alphaBeta(const Pos& pos, int depth, double alpha, double beta) {
  if ((counter++ & 1023) == 0) {
    if (clock() > t0 + CLOCKS_PER_SEC * 2.5) {
      done();
      cerr.flush();
      cout.flush();
      exit(0);
    }
  }
  State& s = table[pos.hash];
  assert(s.depth <= depth);
  if (depth == 0) {
    if (s.depth == 0) {
      return s.alpha;
    }
    s.depth = 0;
    return s.alpha = s.beta = evaluate(pos);
  }
  Move bestMove;
  if (s.depth == depth) {
    alpha = max(alpha, s.alpha);
    beta = min(beta, s.beta);
    if (alpha >= beta) {
      return beta;
    }
    if (s.alpha > -INF) {
      int i = s.bestMove.fromi;
      int to = s.bestMove.to;
      int to2 = s.bestMove.to2;
      Pos pos1 = pos;
      pos1.move(i, to, to2);
      double val = -alphaBeta(pos1, depth - 1, -beta, -alpha);
      if (val >= beta) {
        if (s.depth < depth) {
          s.depth = depth;
          s.alpha = -INF;
          s.beta = INF;
        }
        if (val > s.alpha) {
          s.alpha = val;
          s.bestMove = Move(i, to, to2);
        }
        return beta;
      }
      if (val > alpha) {
        alpha = val;
        bestMove = Move(i, to, to2);
      }
    }
  }
  int128_t mask = pos.f;
  for (int i = 0; i < 4; ++i) {
    mask.resetBit(pos.amazons1[i]);
    mask.resetBit(pos.amazons2[i]);
  }
  double alpha0 = alpha;
  for (int i = 0; i < 4; ++i) {
    int from = pos.amazons1[i];
    mask.setBit(from);
    for (int m : moves) {
      for (int to = from + m; mask.getBit(to); to += m) {
        for (int m2 : moves) {
          for (int to2 = to + m2; mask.getBit(to2); to2 += m2) {
            Pos pos1 = pos;
            pos1.move(i, to, to2);
            double val = -alphaBeta(pos1, depth - 1, -beta, -alpha);
            if (val >= beta) {
              if (s.depth < depth) {
                s.depth = depth;
                s.alpha = -INF;
                s.beta = INF;
              }
              if (val > s.alpha) {
                s.alpha = val;
                s.bestMove = Move(i, to, to2);
              }
              return beta;
            }
            if (val > alpha) {
              alpha = val;
              bestMove = Move(i, to, to2);
            }
          }
        }
      }
    }
    mask.resetBit(from);
  }
  if (s.depth < depth) {
    s.depth = depth;
    s.alpha = -INF;
    s.beta = INF;
  }
  if (alpha0 < alpha) {
    s.alpha = s.beta = alpha;
    s.bestMove = bestMove;
  } else {
    s.beta = alpha;
  }
  return alpha;
}

int main() {
  assert(!(-INF > -INF));
  srand(32);
  for (int i = 0; i < 128; ++i) {
    magic0[i] = ((int64_t)rand() << 32) | rand();
    magic1[i] = ((int64_t)rand() << 32) | rand();
    magic2[i] = ((int64_t)rand() << 32) | rand();
  }
  pos0.f = int128_t(0, 0);
  char c0;
  cin >> c0;
  int n, m;
  cin >> n >> m;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < 10; ++i) {
    string line;
    cin >> line;
    for (int j = 0; j < 10; ++j) {
      pos0.f.setBit(i * 12 + j + 1);
      if (line[j] == c0) {
        pos0.amazons1[c1++] = i * 12 + j + 1;
      } else if (line[j] == 'B' || line[j] == 'W') {
        pos0.amazons2[c2++] = i * 12 + j + 1;
      } else if (line[j] == '.') {
        pos0.f.resetBit(i * 12 + j + 1);
      }
    }
  }
  pos0.initHash();
  for (int depth = 1; ; ++depth) {
    if (!(alphaBeta(pos0, depth, -INF, INF) < INF)) {
      break;
    }
  }
  done();
  return 0;
}

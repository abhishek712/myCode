/*
 * N Puzzle
N Puzzle is a sliding blocks game that takes place on a k * k grid with ((k * k) - 1) tiles each numbered from 1 to N. Your task is to reposition the tiles to their proper order.

Input Format

The first line of the input contains an integer k, the size of the square grid. k * k lines follow each line containing an integer I on the tile starting from the top left to bottom right. The empty cell is represented by the number 0.

N = (k * k) -1
0 <= I <= N

Constraints

3 <= k <= 5

Output Format

The first line contains an integer, M, the number of moves your algorithm has taken to solve the N-Puzzle. M lines follow. Each line indicating the movement of the empty cell (0).

A grid is considered solved if it is of the following configuration.

0 1 2
3 4 5
6 7 8
Sample Input

3
0
3
8
4
1
7
2
6
5
Sample Output

70
RIGHT
DOWN
...
...
...
Explanation

The board given as input is

0 3 8
4 1 7
2 6 5
After RIGHT, the board¡¯s configuration is

3 0 8
4 1 7
2 6 5
Task

Print all the moves made from the given configuration to the final solved board configuration.

Scoring

On successfully solving the puzzle, your score will be k * k.
 * 
 * 
 */

import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Solution {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		NPuzzle solver = new NPuzzle();
		solver.solve(1, in, out);
		out.close();
	}
}

class NPuzzle {
	int[][] board;
	int[][] target;
	List<String> answer = new ArrayList<String>();
	boolean[][] fixed;
	int row;
	int column;
	int[] queueRow;
	int[] queueColumn;
	int[][] direction;
	boolean[][] visited;
	String[] directions = {"UP", "RIGHT", "DOWN", "LEFT"};
	Random random = new Random(239);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int size = in.readInt();
		fixed = new boolean[size][size];
		board = IOUtils.readIntTable(in, size, size);
		target = new int[size][size];
		visited = new boolean[size][size];
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				target[i][j] = i * size + j;
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j] == 0) {
					row = i;
					column = j;
				}
			}
		}
		direction = new int[size][size];
		queueRow = new int[size * size];
		queueColumn = new int[size * size];
		if (go(size, size)) {
			out.printLine(answer.size());
			for (String s : answer)
				out.printLine(s);
		} else
			out.printLine(0);
    }

	private boolean go(int rowCount, int columnCount) {
		if (rowCount == 3 && columnCount == 2) {
			int i = 0;
			while (!valid()) {
				i++;
				if (i > 200000)
					return false;
				int direction = random.nextInt(4);
				int nextRow = row + MiscUtils.DX4[direction];
				int nextColumn = column + MiscUtils.DY4[direction];
				if (MiscUtils.isValidCell(nextRow, nextColumn, 3, 2)) {
					answer.add(directions[direction ^ 2]);
					board[row][column] = board[nextRow][nextColumn];
					row = nextRow;
					column = nextColumn;
					board[row][column] = 0;
				}
			}
			return true;
		}
		if (rowCount > 3) {
			for (int j = columnCount - 1; j > 0; j--) {
				move(target[rowCount - 1][j], rowCount - 1, j);
				fixed[rowCount - 1][j] = true;
			}
			move(target[rowCount - 1][0], rowCount - 2, 0);
			if (row == rowCount - 1 && column == 0) {
				answer.add("UP");
				fixed[rowCount - 1][0] = true;
				board[rowCount - 1][0] = board[rowCount - 2][0];
				board[rowCount - 2][0] = 0;
				row--;
			} else {
				fixed[rowCount - 2][0] = true;
				goTo(rowCount - 2, 2);
				answer.add("DOWN");
				answer.add("LEFT");
				answer.add("LEFT");
				answer.add("UP");
				answer.add("RIGHT");
				answer.add("DOWN");
				answer.add("RIGHT");
				answer.add("UP");
				board[rowCount - 2][0] = board[rowCount - 2][1];
				board[rowCount - 2][1] = board[rowCount - 1][0];
				board[rowCount - 1][0] = target[rowCount - 1][0];
				fixed[rowCount - 1][0] = true;
				fixed[rowCount - 2][0] = false;
			}
			return go(rowCount - 1, columnCount);
		}
		if (columnCount > 2) {
			for (int j = rowCount - 1; j > 0; j--) {
				move(target[j][columnCount - 1], j, columnCount - 1);
				fixed[j][columnCount - 1] = true;
			}
			move(target[0][columnCount - 1], 0, columnCount - 2);
			if (row == 0 && column == columnCount - 1) {
				answer.add("LEFT");
				fixed[0][columnCount - 1] = true;
				board[0][columnCount - 1] = board[0][columnCount - 2];
				board[0][columnCount - 2] = 0;
				column--;
			} else {
				fixed[0][columnCount - 2] = true;
				goTo(2, columnCount - 2);
				answer.add("RIGHT");
				answer.add("UP");
				answer.add("UP");
				answer.add("LEFT");
				answer.add("DOWN");
				answer.add("RIGHT");
				answer.add("DOWN");
				answer.add("LEFT");
				board[0][columnCount - 2] = board[1][columnCount - 2];
				board[1][columnCount - 2] = board[0][columnCount - 1];
				board[0][columnCount - 1] = target[0][columnCount - 1];
				fixed[0][columnCount - 1] = true;
				fixed[0][columnCount - 2] = false;
			}
			return go(rowCount, columnCount - 1);
		}
		throw new RuntimeException();
	}

	private boolean valid() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				if (board[i][j] != target[i][j])
					return false;
			}
		}
		return true;
	}

	private void move(int what, int targetRow, int targetColumn) {
		while (true) {
			int curRow = -1;
			int curColumn = -1;
			for (int i = 0; i < board.length; i++) {
				for (int j = 0; j < board.length; j++) {
					if (board[i][j] == what) {
						curRow = i;
						curColumn = j;
					}
				}
			}
			if (curRow == targetRow && curColumn == targetColumn)
				return;
			fixed[curRow][curColumn] = true;
			goTo(targetRow, targetColumn);
			fixed[curRow][curColumn] = false;
			goTo(curRow, curColumn);
		}
	}

	private void goTo(int targetRow, int targetColumn) {
		if (targetRow == row && targetColumn == column)
			return;
		ArrayUtils.fill(visited, false);
		direction[row][column] = -1;
		visited[targetRow][targetColumn] = true;
		queueRow[0] = targetRow;
		queueColumn[0] = targetColumn;
		int size = 1;
		for (int i = 0; i < size; i++) {
			int curRow = queueRow[i];
			int curColumn = queueColumn[i];
			for (int j = 0; j < 4; j++) {
				int nextRow = curRow + MiscUtils.DX4[j];
				int nextColumn = curColumn + MiscUtils.DY4[j];
				if (MiscUtils.isValidCell(nextRow, nextColumn, board.length, board.length) && !fixed[nextRow][nextColumn] && !visited[nextRow][nextColumn]) {
					visited[nextRow][nextColumn] = true;
					queueRow[size] = nextRow;
					queueColumn[size++] = nextColumn;
					direction[nextRow][nextColumn] = j;
				}
			}
		}
		if (direction[row][column] == -1)
			throw new RuntimeException();
		while (row != targetRow || column != targetColumn) {
			answer.add(directions[direction[row][column]]);
			int nextRow = row + MiscUtils.DX4[direction[row][column] ^ 2];
			int nextColumn = column + MiscUtils.DY4[direction[row][column] ^ 2];
			board[row][column] = board[nextRow][nextColumn];
			row = nextRow;
			column = nextColumn;
		}
		board[row][column] = 0;
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

	}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

    public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
		return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
	}

	}

class ArrayUtils {

	public static void fill(boolean[][] array, boolean value) {
		for (boolean[] row : array)
			Arrays.fill(row, value);
	}

    }
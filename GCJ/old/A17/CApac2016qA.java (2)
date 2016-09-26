import java.io.*;
import java.util.*;

public class CApac2016qA {

    static int r, c;
    static double p, q;
    static char a[][];
    static double _p[], _q[];
    static int cnt[][];
    static int dx[] = {-1, +1, 0, 0};
    static int dy[] = {0, 0, -1, +1};
    
    public static void main(String args[]) throws Exception {
        InputReader in;
        PrintWriter w;
        boolean online = true;
        String fileName = "A-large";

        if (online) {
            in = new InputReader(new FileInputStream(new File(fileName + ".in")));
            w = new PrintWriter(new FileWriter(fileName + "out.txt"));
        } else {
            in = new InputReader(System.in);
            w = new PrintWriter(System.out);
        }

        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            
            r = in.nextInt();
            c = in.nextInt();
            
            int rs = in.nextInt();
            int cs = in.nextInt();
            int s = in.nextInt();
            
            p = Double.parseDouble(in.readString());
            q = Double.parseDouble(in.readString());
            
            _p = new double[2 * s + 10];
            _q = new double[2 * s + 10];
            _p[0] = _q[0] = 1;
            for (int i = 1; i < _p.length; i++) {
                _p[i] = _p[i - 1] * (1 - p);
                _q[i] = _q[i - 1] * (1 - q);
            }
            
            a = new char[r][c];
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    a[i][j] = in.readString().charAt(0);
            
            cnt = new int[r][c];
            cnt[rs][cs] = -1;
            
            double ans = go(rs, cs, s, 0);
            
            w.print("Case #" + t + ": ");
            w.println(ans);
        }

        w.close();
    }
    
    static double go(int rs, int cs, int s, double now) {
        if (rs < 0 || rs >= r || cs < 0 || cs >= c)
            return 0;
        //System.out.println(rs + " " + cs + " " + s + " " + now);
        if (s == -1)
            return now;
        
        now -= P(rs, cs, cnt[rs][cs]);
        cnt[rs][cs]++;
        now += P(rs, cs, cnt[rs][cs]);
        
        double ans = 0;
        for (int k = 0; k < 4; k++) {
            ans = Math.max(ans, go(rs + dx[k], cs + dy[k], s - 1, now));
        }
        
        now -= P(rs, cs, cnt[rs][cs]);
        cnt[rs][cs]--;
        now += P(rs, cs, cnt[rs][cs]);
        
        return ans;
    }
    
    static double P(int x, int y, int c) {
        if (c == -1)
            return 0;
        if (a[x][y] == 'A')
            return P(c);
        else
            return Q(c);
    }
    
    static double P(int cnt) {
        return 1 - _p[cnt];
    }
    
    static double Q(int cnt) {
        return 1 - _q[cnt];
    }

    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}

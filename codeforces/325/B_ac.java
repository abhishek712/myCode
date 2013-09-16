import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) throws Exception {

		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		scan.close();
		BigInteger N=BigInteger.valueOf(n);
		TreeSet<BigInteger> ts = new TreeSet<BigInteger>();
		for(int i=0;i<=62;i++){
			long t=1L<<i;
			if(t<2*n||i<2){
				BigInteger B=BigInteger.valueOf(t*2-3);
				BigInteger Temp=B.pow(2);
				Temp=Temp.add(N.multiply(BigInteger.valueOf(8)));
				BigInteger S=sqrt(Temp);
				if(S.multiply(S).equals(Temp)){
					BigInteger K1=(B.negate().add(S));
					if(K1.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)){
						K1=K1.divide(BigInteger.valueOf(2));
						if(K1.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)){
							BigInteger K=BigInteger.valueOf(1L<<(i)).multiply(K1);
							ts.add(K);
						}
					}
				}
			}
		}
		Iterator iterator;
		iterator = ts.iterator();
		if(ts.size()!=0){
		while (iterator.hasNext()){
			System.out.println(iterator.next() + "");
		}
		}
		else
			System.out.println(-1);

	}

	public static BigInteger sqrt(BigInteger n) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		while(b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
			else a = mid.add(BigInteger.ONE);
		}
		return a.subtract(BigInteger.ONE);
	}
}
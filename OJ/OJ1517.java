import java.io.*;
import java.util.*;
import java.math.*;

public class OJ1517{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		BigInteger a = in.nextBigInteger();
		BigInteger b = in.nextBigInteger();
		BigInteger c = a.subtract(b);
		System.out.println(c);
	}
}
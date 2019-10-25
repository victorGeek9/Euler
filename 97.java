import java.math.BigInteger;
import static java.math.BigInteger.*;
public class Dispatcher {
	public static void main(String[] args) {
		BigInteger mod = new BigInteger("10000000000");
		BigInteger mul = new BigInteger("28433");
		BigInteger result = new BigInteger("2");
		BigInteger temp;
		temp = result.pow(7830457);
		result = temp.mod(mod);
		temp = result.multiply(mul);
		result = temp.mod(mod);
		mul = new BigInteger("1");
		temp = result.add(mul);
		System.out.print(temp);
	}
}

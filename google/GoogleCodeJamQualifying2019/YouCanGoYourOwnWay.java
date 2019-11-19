
import java.util.*;
import java.math.*;

public class Solution {
	public static void main(String args[] ) throws Exception {
		// your code goes here

		Scanner in = new Scanner(System.in);
		int i,l,j,t = in.nextInt();
		
		int caseNo = 0;
		while(t!=0) {
			caseNo++;
			long n = in.nextLong();
			String input = in.next();
			
			String ans = "";
			
			for(i=0;i<2*n-2;i++){
				if(input.charAt(i) == 'E')
					ans += 'S';
				else
					ans += 'E';
			}
			System.out.println("Case #" + caseNo + ": " + ans);
			
			
			t--;
		}
	}
}
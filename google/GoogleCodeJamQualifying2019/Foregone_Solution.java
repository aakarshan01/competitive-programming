
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
			String num = in.next();
			char []firstNum = new char[num.length()];
			char []secondNum = new char[num.length()];
			for(i=0;i<num.length();i++){
				firstNum[i] = num.charAt(i);
				secondNum[i] = '0';
			}
			for(i=0;i<num.length();i++){
				if(firstNum[i] == '4'){
					firstNum[i] = '3';
					secondNum[i] = '1';
				}
			}
			System.out.print("Case #" + caseNo + ": " );
			for(i=0;i<num.length();i++){
				System.out.print(firstNum[i]);
			}
			System.out.print(" ");
			int found = 0;
			for(i=0;i<num.length();i++){
				if(secondNum[i] == '0' && found == 0)
					continue;
				found =1;
				System.out.print(secondNum[i]);
			}
			System.out.println();
			t--;
		}
	}
}
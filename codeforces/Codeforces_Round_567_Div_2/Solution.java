
import java.util.*;
import java.math.*;

public class Solution {
	public static void main(String args[] ) throws Exception {
		// your code goes here

		Scanner in = new Scanner(System.in);
		int i,j=0,l = in.nextInt();
		String s;
			s = in.next();
		
		int mid = s.length()/2;
		int present = -1;
		int array[] = new int[3];
		i=mid;
		if(s.charAt(mid)!='0'){
			array[j++]=mid;
			present = 1;
		}
		while(i<s.length()-1){
			i++;
			if(s.charAt(i)!='0'){
				array[j++]=i;
				break;
			}
		}
		i=mid;
		while(i>1){
			i--;
			if(s.charAt(i)!='0'){
				array[j++]=i;
				break;
			}
		}
		
		//for(i=0;i<j;i++)
			//System.out.println("index=" + array[i]);
		//System.out.println("s.length = " + s.length());
		BigInteger min = new BigInteger(s);
		
		if(present==1){
			if(s.charAt(mid-1)!='0')
				j=Math.min(j, 2);
			else
				j=1;
		}
		else
			j=Math.min(j, 2);
		for(i=0;i<j;i++){
			String s1 = s.substring(0,array[i]);
			String s2 = s.substring(array[i]);
			//System.out.println(s1 + " " + s2);
			BigInteger n1 = new BigInteger(s1);
			BigInteger n2 = new BigInteger(s2);
			
			n1 = n1.add(n2);
			if(n1.compareTo(min)<0)
				min = n1;
		}
		System.out.println(min);
	}
}
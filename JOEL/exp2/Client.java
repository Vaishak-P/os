import java.net.*;
import java.io.*;

public class Client {
	public static void main(String[] args) throws Exception {
		Socket s=new Socket("localhost",9999);
		DataInputStream din=new DataInputStream(s.getInputStream());
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str="",str2="";
		while(!str.equals("stop")){
			System.out.println("\nEnter Message: ");
			str=br.readLine();
			dout.writeUTF(str);
			dout.flush();
			
		}
		dout.close();
		s.close();
	}
}

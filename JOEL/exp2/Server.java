import java.net.*;
import java.io.*;
public class Server {
	public static void main(String args[]) throws Exception,UnknownHostException{
		ServerSocket ss=new ServerSocket(9999);
		Socket s=ss.accept();
		DataInputStream din=new DataInputStream(s.getInputStream());
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		String str="";
		while(str!="stop"){
			str=din.readUTF();
			System.out.println("Client: "+str);
			dout.flush();
		}
		din.close();
		s.close();
		ss.close();
	}
}

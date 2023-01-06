import java.io.*;
import java.net.*;

public class Client{
    public static void main(String[] args){
        new Client();
    }
        public Client(){
            Socket socket;
            String host="localhost";
            try{
                socket = new Socket(host,Server.PORT_NUMBER);
                
            }catch(UnknownHostException ex){
                System.out.println(host+ " is not a valid host name ");
                return;
            }catch(IOException ex){
                System.out.println("error communication with "+ host);
                return;
            }
            //initialize model,GUI,etc...
            InputStream in = null;
            OutputStream out = null;
            try{
                in = socket.getInputStream();
                out = socket.getOutputStream();
                //do useful stuff
            }catch(IOException i){
                System.out.println(i); 
            }finally{
                try{
                    in.close();
                    out.close();
                    socket.close();
		    System.out.println("ExitiCng");
               }catch(IOException ex){
                   // not much can be done...
                }
            }
        }
    }

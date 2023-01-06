import java.io.*;
import java.net.*;

public class Server extends Thread{
    public static final int PORT_NUMBER = 24357;
    protected Socket socket;

    public static void main(String[] args){
        ServerSocket server = null;
        try{
            server = new ServerSocket(PORT_NUMBER);
            while (true){
                System.out.println("Waiting for connection.....");
                new Server(server.accept());
            }
        }catch(IOException ex){
            System.out.println("Unable to start server or accept connection");
            System.exit(1);
        }finally{
            try{
                server.close();
            }catch(IOException ex){
                //not much can be done: log the error
                //exits since this is the end of main 
            }
        }
    }
    private Server (Socket socket){
        this.socket = socket;
        start();
    }//server services client request im the run method
    public void run(){
        InputStream in = null;
        OutputStream out = null;
        try{
            in = socket.getInputStream();
            out = socket.getOutputStream();
            System.out.println("connection Successfull");
            //do useful stuff
        }catch(IOException ex){
            System.out.println("Unable to get streams from client");
        }finally{
            try{
                in.close();
                out.close();
                socket.close();
            }catch(IOException ex){
                //not much can be done: log the error
            }
        }

    }
}

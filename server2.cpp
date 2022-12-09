#include <iostream>
#include <bits/stdc++.h>
#include <string>
// #include<vector>
#include<bits/stdc++.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include<thread>
using namespace std;
sockaddr_in servAddr;
char msg[1500];
int port, serverSd, bindStatus;



void fun(){                                                    
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);
                                                             //accept, create a new socket descriptor to
                                                              //handle the new connection with client                      
    int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    if(newSd < 0)
    {
    cerr << "Error accepting request from client!" << endl;
    exit(1);
    }
    cout << "Connected with client!" << endl;
  

    char msg[1000];
    recv(newSd, (char*)&msg, sizeof(msg), 0);

    string requestedFilee="";
    string ticketname="";
    for(int i=0;i<1;i++)
    requestedFilee+=msg[i];

    cout<<requestedFilee<<endl;
    //bool ifExists = checkForFile(requestedFilee);
      bzero((char*)&msg, sizeof(msg)); 

   // unordered_map<string,vector<string>> m;
    //m["prathvi_singh"].push_back("12345678");                  
    string name11="",address22="";
     int flag111=0;
    if(requestedFilee=="1"){                                                // here we checking condition like 1 for login (taking name(userid) && password)
        string s="Enter userid and password";
 
        char returnMessage[1000];
        strcpy(returnMessage,s.c_str());
        char login[1000];
        send(newSd, (char*)&returnMessage, strlen(returnMessage), 0);
        recv(newSd, (char*)&login, sizeof(login), 0);
        string d=login,r,r1,r2,r0;
        
        for(int i=0;i<d.size();i++){
            if(d[i]=='#'){
                r=d.substr(0,i);
                r1=d.substr(i+1);
                break;
            }
        }
        ticketname=r;
        string f1,f2,f3,f4;
        int flag=1;
        fstream in;
        in.open("files.txt");
        while(!(in.eof())){                                              // here matching name and password with store data
          in>>f1>>f2>>f3>>f4;
          cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;                    // also finding address relate to name(userid) , we use this address to show them random plans related   
          if(f1==r && f4==r1){                                                                    // to their home addressl
         address22=f2;
          flag=0;
                 r2="Hi " + r + " ,login successful\n";
            }                                                        // we information unmatched then he will try again
        }
     //   if(m.find(r)!=m.end() && m[r][0]==r1){
         //   r2="Hi " + r + " ,login successful\n";
    //    }
        if(flag){
        flag111=1;
         r2="Wrong information";

        }
        cout<<login<<endl;
        char returnMessage2[1000];
        strcpy(returnMessage2,r2.c_str());
        send(newSd, (char*)&returnMessage2, strlen(returnMessage2), 0);
        
        
    }

     else if(requestedFilee=="2"){                                  // 2 for create account / for new users
        string s="Enter the name",s1,s2,s3;
        char returnMessage[1000];
        strcpy(returnMessage,s.c_str());                              //    taking name by sending the request and getting the name by request
        char d[1000];
        send(newSd, (char*)&returnMessage, strlen(returnMessage), 0);
       
        recv(newSd, (char*)&d, sizeof(d), 0);
        
        string r=d,r1,r2,r3;                                       //  taking address by sending the request and receiving the address by request
        bzero((char*)&returnMessage, sizeof(returnMessage)); 
        ticketname=d;
        s1="Enter the Address(city)";
        strcpy(returnMessage,s1.c_str());
        char d1[1000];
        send(newSd, (char*)&returnMessage, strlen(returnMessage), 0);
        recv(newSd, (char*)&d1, sizeof(d1), 0);
           
        r1=d1;
         bzero((char*)&returnMessage, sizeof(returnMessage));  // here taking mobile no
        s2="Enter the Mobile no";
        strcpy(returnMessage,s2.c_str());
        char d2[1000];
        send(newSd, (char*)&returnMessage, strlen(returnMessage), 0);
        recv(newSd, (char*)&d2, sizeof(d2), 0);
        
        r2=d2;
         bzero((char*)&returnMessage, sizeof(returnMessage));  // here taking password
        s3="Enter the Password";
        strcpy(returnMessage,s3.c_str());
        char d3[1000];
        send(newSd, (char*)&returnMessage, strlen(returnMessage), 0);
        recv(newSd, (char*)&d3, sizeof(d3), 0);
        
        r3=d3;
        
     
       address22=r1; 
                                                              // store this all information to txt file
        fstream f;
        f.open("files.txt",ios:: in|ios::out|ios::app);
        f<<r<<" "<<r1<<" "<<r2<<" "<<r3<<endl;
  
   
    }
    else{                                           // type 3 or any other nnumber to exit

       close(newSd);
    }
    
    
    if(flag111==0){
     string s11,s12="";
     int addr=address22.size();
     ifstream places;
                                                                          // are you remember above we take address to show the places
    places.open("files1.txt");
   while(   getline(places,s11)){                                        // we use address here
      if(s11.substr(0,addr)==address22){
      s12=s12+s11+"#";
}
     
   
    }
    if(s12.size()==0) s12="No plan found relative to your address ,please enter the places";         // if address is unmatched with our data , it mean this address used rarely
    cout<<s12<<endl;
                                                                                                   // therefore we have no information we will save it and use it for future
    char d4[1000],d5[1000],d6[1000],d7[1000];
    char returnMessage11[1000],returnMessage12[1000],returnMessage14[1000];
    strcpy(returnMessage11,s12.c_str());
    send(newSd, (char*)&returnMessage11, strlen(returnMessage11), 0);
    recv(newSd, (char*)&d5, sizeof(d5), 0);
    string er=d5;
    cout<<d5<<endl;
    bzero((char*)&d5, sizeof(d5)); 
      
      
    string from="From city1";                                                        // here we taking city from the user (starting point of journey)
    strcpy(returnMessage12,from.c_str());
    send(newSd, (char*)&returnMessage12, strlen(returnMessage12), 0);
    recv(newSd, (char*)&d5, sizeof(d5), 0);
    //cout << from << endl;
    string city1=d5,c1,c2,c3;
    
    cout<< from << ": " <<city1<<endl;
    
    string to="To city2";
    strcpy(returnMessage14,to.c_str());                                        // here we taking end point of journey form user
    send(newSd, (char*)&returnMessage14, strlen(returnMessage14), 0);
    recv(newSd, (char*)&d6, sizeof(d6), 0);
    string to11=returnMessage14;
    //cout<<to11<<endl;
    string city2=d6;
    
    cout << to11 << ": "<<city2<<endl; 
    
    string de="",s123="";
     int h1=8;
    int n1=city1.size();
    int m1=city2.size();
    string c21,c22;
    unordered_map<string,string> m12;
    int a11=1;
    ifstream g;
    g.open("train.txt");
    

    while( getline(g,de) ){
  // g>>de;
                                                               // here we matching start point and end point to our plans (checking how many trip is able for this root)
    c21=de.substr(0,n1);
    c22=de.substr(n1+4,m1);
  if( c21==city1 && c22==city2){
//cout<<de.substr(0,n1)<<endl;
//cout<<de.substr(n1+4,m1)<<endl;;
    m12[to_string(a11)]=de;
    s123=s123+de+"#";
    cout<<de<<endl;
    a11++;
  }
                                                
   }                                                         // if unmatched its mean , we have no plan (no trip)  or (some spelling mistake)       
   char msg13[1000];
   if(s123.size()==0) s123="Re Enter the places";
   strcpy(msg13,s123.c_str());
   send(newSd, (char*)&msg13, strlen(msg13), 0);
   recv(newSd, (char*)&d7, sizeof(d7), 0);
   string w2=d7;
   
   
                                                         // to select the trip and making proper ticket and store it in txt file
   string select=m12[w2];
   char msg14[1000];
   strcpy(msg14,select.c_str());
   send(newSd, (char*)&msg14, strlen(msg14), 0); 
   cout<<m12[w2]<<endl;
   string s19="Your ticket";
   string s20="------------------------------------------";
   fstream tick;
   tick.open("ticket.txt");
   tick<<"       "<<s19<<endl;
   tick<<s20<<endl;
   tick<<"      "<<ticketname<<endl;
   tick<<"    "<<city1<<" - "<<city2<<endl;
   tick<<select<<endl;
   tick<<s20<<endl;
    close(newSd);
}
else{
 close(newSd);
}   
   
   
    close(newSd);
}
int main(int argc, char *argv[])
{

    ios::sync_with_stdio(false);
    //for the server, we only need to specify a port number
    if(argc != 2)
    {
    cerr << "Usage: port" << endl;
    exit(0);
    }
    //grab the port number
    port = atoi(argv[1]);
    //buffer to send and receive messages with

    //setup a socket and connection tools
    bzero((char*)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);

    //open stream oriented socket with internet address
    //also keep track of the socket descriptor
    serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSd < 0)
    {
    cerr << "Error establishing the server socket" << endl;
    exit(0);
    }
    //bind the socket to its local address
    bindStatus = bind(serverSd, (struct sockaddr*) &servAddr,
    sizeof(servAddr));
    if(bindStatus < 0)
    {
    cerr << "Error binding socket to local address" << endl;
    exit(0);
    }
    cout << "Waiting for a client to connect..." << endl;
    //listen for up to 5 requests at a time
    listen(serverSd, 5);
    // fun();
    // ----------------------------------------------------------------
    // Multi
    thread th1[100];
    int ind = 0;
    while(ind<100){
    th1[ind++]=thread(fun);
    }
    ind =0;
    while(ind<100){
		th1[ind++].join();
}
// ----------------------------------------------------------------


close(serverSd);
cout << "********Session********" << endl;
// cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << endl;
// cout << "Elapsed time: " << (end1.tv_sec - start1.tv_sec)
// << " secs" << endl;
cout << "Connection closed..." << endl;
return 0;
}



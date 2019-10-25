#include <iostream>
#include "Packet.h"
#include "Range.h"
#include "Socket.h"
#include <vector>

Range range;
vector<Router> neighbor;
Address address;

struct Router{
	Range rng;
	Address addr;
};

void handlePacket(Packet p){
	if(p.type == Joinrequest){
		Joinrequest* jr = (Joinrequest*) p.payload;
	}
	if(range.contains(jr.dest)){
		Range rv = range.split();
		Joinresponse* jp = (Joinresponse*) p.payload;
		jp.range = range.split();
	//	p.src = address p.type;
	}else if(p.type == Joinresponse){
		joinresponse* jp = (Joinresponse*)p.payload;
		range = jp->range;
	}else if(p.type == PEEP_UPDATE){
		neightborsUpdate* nu = (neighborUpdate*)p.payload;
		Router r;
		r.address = p.src;
	}else{
		Route(p);
	}
}

void Route(Packet p){
	int closest = 10;
	Router who = neighbors[0];
	for(Router r : peeps){
		if(r.range.contains(jr.dest)){
			closest = 0;
			who = r;
		}else if(r.range.midpoint.distance(jr.dest) < closest){
			closest = r.range.midpoint.distance(jr.dest);
			who = r;
		}
	}
	SendPacket(p);
}

void SendPacket(Packet& p){
	Socket sock;
	sock.open(p.dest host, to_String(p.dest port));
	sock.writeBytes(&p, sizeof(Packet));
	sock.close();
}

void server(string port){
    vector<Socket> sockets(1);
    sockets[0].listen(port);

    while(true){
        waitForEvent(sockets,-1);
        if(sockets[0].isClosed){
            return;
        }else if(sockets[0].hasData){
            sockets.push_back(sockets[0].accept());
        }

        for(int i = sockets.size()-1; i >= 1; i-=1){
            if(sockets[i].isClosed){
                cout << sockets[i].host << " has left" << endl;
                sockets.erase(sockets.begin()+i);
            }else if(sockets[i].hasData){
				
			
			}
		}
	}
}

int main(int argc, char* argv[]){
	
    if(argc == 2){
        //port number so this is the server
        server(argv[1]);
    }else if(argc == 3){
        //client
        client(argv[1],argv[2]);
    }


	return 0;
}

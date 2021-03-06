lane.cpp                                                                                            000644  000765  000024  00000002011 13361743376 012722  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//prog1
//10/17/18
//using object oriented programming to
//simulate the car in the lanes



#include "lane.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


//constructor
Lane :: Lane(int location, bool flag):light(flag)
{
        this->location =location;
        head = NULL;
}


// add the car in the lane
void Lane::addCar(Car *my_car){
        if(head == NULL)
        {
                head = my_car;
		return;
        }
        else{
                my_car->set_next(head->get_next());
                head->set_next(my_car);
        }
}



// destructor
// data member: Car*head, stoplight light
Lane :: ~Lane()
{
}



// get the head pointer in the lane
Car* Lane :: get_head()
{
	return head;
}


//set the head in the lane
void Lane :: set_head(Car *car)
{
	head= car;
}


// get the location in the lane 
int Lane :: get_location()
{
	return location;
}



//get the information that if the car can pass 
bool Lane :: get_sl_pass()
{
	return light.get_pass();
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       location.cpp                                                                                        000644  000765  000024  00000000606 13361703002 013601  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented programming to 
//simulate the car in the lanes




#include "location.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//constructor
Location :: Location()
{
        location=0;
}


//constructor
Location :: Location(int loca) : location(loca)
{
}

//destructor
Location :: ~Location(){}

                                                                                                                          main.cpp                                                                                            000644  000765  000024  00000003613 13361746134 012733  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes




#include <iostream>
#include <cctype>
#include <cstring>
#include "map.h"
#include "stoplight.h"
#include "lane.h"
#include "location.h"
#include "car.h"
#define SIZE 30



using namespace std;

int main(){
	map Map(5);
	
	Car *my_car1 = new Car(100,"A",1,1);
	Car *my_car2 = new Car(90,"B",1,1);
	Car *my_car3 = new Car(60,"C",1,1);

	Car *my_car4 = new Car(100,"D",2,1);
	Car *my_car5 = new Car(100,"E",2,1);
	Car *my_car6 = new Car(90,"F",2,1);

	Car *my_car7 = new Car(60,"G",3,1);
	Car *my_car8 = new Car(100,"QQQ",3,1);
	Car *my_car9 = new Car(100,"Z",3,1);

	Car *my_car10 = new Car(90,"X",4,1);
	Car *my_car11 = new Car(60,"N",4,1);
	Car *my_car12 = new Car(100,"QQ",4,1);


	Car *my_car13= new Car(100,"ABC",0,1);
	Car *my_car14 = new Car(90,"T",0,1);
	Car *my_car15= new Car(60,"ZZ",0,1);
				

	Map.addCar(my_car1);			//Lane1 cars
	Map.addCar(my_car2);	
	Map.addCar(my_car3);

	Map.addCar(my_car4);			//Lane2 cars
	Map.addCar(my_car5);
	Map.addCar(my_car6);	

	Map.addCar(my_car7);			//Lane3 cars
	Map.addCar(my_car8);
	Map.addCar(my_car9);

	Map.addCar(my_car10);			//Lane4 cars
	Map.addCar(my_car11);
	Map.addCar(my_car12);	

	Map.addCar(my_car13);			//Lane0 cars
	Map.addCar(my_car14);	
	Map.addCar(my_car15);

	cout<<"*******Welcome to use!********************************************"<<endl;

	cout<<"*******sl is stoplight, 1 is Red light, 0 is Green light!*********"<<endl;
	cout<<"***When car meet the Red light(1), the car can not Move and Add!!!***"<<endl;

	Map.display();

	cout<<"Lane 1 car 1 move to Lane2:"<<endl;
	cout<<"Lane 2 car 5 move to Lane1"<<endl;
	cout<<"Lane 3 car 7 move to Lane4"<<endl;
	cout<<"******************************************"<<endl;
	my_car1->move_car(2,Map);
	my_car5->move_car(1,Map);
	my_car7->move_car(4,Map);
	cout<<endl;

	Map.display();
	return 0;



}
                                                                                                                     map.cpp                                                                                             000644  000765  000024  00000005411 13361743613 012561  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes

#include "map.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

//constructor
map :: map(int size)
{
        lane_size= size;
        list = new Lane *[lane_size];
	srand(time(0));
	bool rand_0_1 = rand() % 2;
        for(int i=0; i<lane_size; i++)
        {
		rand_0_1 = rand() % 2;
                list[i]= new Lane(i, rand_0_1);
        }

}


//destructor
map :: ~map()
{
	for(int i=0; i<lane_size;i++){
		delete list[i];
	}
	delete []list;
}



//add the car in the map
void map :: addCar(Car *my_car)
{
	if(my_car->getterLocation() > lane_size || my_car->getterLocation() < 0){
		cout<<"The lane is not in this map"<<endl;
		return;
	}
	if(list[my_car->getterLocation()]->get_sl_pass() == 1){
		cout<<"The stoplight of this lane is red"<<endl;
		return;
	}
        list[my_car->getterLocation()]->addCar(my_car);
}


// display car's information in the map
void map::display_car(Car *head){
        if(!head){
                cout<<"^";
                return;
        }
        cout<<"Car:"<<head->get_name()<<":"<<head->getterLocation()<<"->";
        display_car(head->get_next());
}



//display all information in the map
void map :: display()
{
        for(int i=0;i<lane_size;i++){
                cout<<"Lane"<<list[i]->get_location()<<",sl:"<<list[i]->get_sl_pass()<<"->";
                display_car(list[i]->get_head());
                cout<<endl;
        }
}


//move the car to other lanes
//in the stoplight, 0 is Green light, 1 is Red light
//when stoplight is 1(Red), we can not move the car 
//when stoplight is 0(Green), we can can move the car
void map::move_car(int location, Car *instance){
	if(location > lane_size || location < 0){
		cout<<"The lane is not in this map"<<endl;
		return;
	}
	if(list[location]->get_sl_pass() == 1){
		cout<<"The stoplight of this lane is red"<<endl;
		return;
	}
	int now = instance->getterLocation();
	instance->setLocation(location);
	Car *temp = list[now]->get_head();
	if(list[now]->get_head() == NULL){
		cout<<"The car is not on this lane"<<endl;
		return;
	}
	if(strcmp(instance->get_name(),temp->get_name())==0){
		list[now]->set_head(temp->get_next());
		instance->set_next(list[location]->get_head());
		list[location]->set_head(instance);
		return;
	}
	char *iname = instance->get_name();
	char *tname = temp->get_next()->get_name();
	while( temp->get_next() && strcmp(iname,tname)!=0){
		temp = temp -> get_next();
	}
	if(strcmp(iname,tname) == 0){
		temp->set_next(temp->get_next()->get_next());
		instance->set_next(list[location]->get_head());
		list[location]->set_head(instance);
		return;
	}
	else{
		cout<<"The car is not on this Lane"<<endl;
		return;
	}
	
}
                                                                                                                                                                                                                                                       stoplight.cpp                                                                                       000644  000765  000024  00000000503 13361703002 014002  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes

#include "stoplight.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//constructor
stoplight::stoplight(bool flag)
{
	pass = flag;
}


//destructor
stoplight::~stoplight(){}
                                                                                                                                                                                             car.h                                                                                               000644  000765  000024  00000001746 13361703002 012211  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes




#ifndef car_h
#define car_h
#include "location.h"
class map;
class Car : public Location		//class car is derived by class Location
{
        public:
                Car(int spd, char *name, int location,bool mov);		//constructor
                ~Car();								//destructor
                void setLocation(int loca);					//set the  location 
                int getterLocation();						//get the location information
                Car* get_next();						// get the next pointer 
                void set_next(Car *car);					//set the next pointer 	
                char * get_name();						//get the car name 
		void move_car(int location, map &Map);				//move the car to other lanes
        protected:
                int speed;		//car speed
                char *name;		//car name
                bool status;		// car status
                Car *next;		//next pointer
};
#endif
                          lane.h                                                                                              000644  000765  000024  00000001562 13361743340 012370  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes



#ifndef lane_h
#define lane_h
#include "location.h"
#include "car.h"
#include "stoplight.h"
class Location;
class car;

class Lane: public Location				//class car is derived by class Location
{
        public:
                Lane(int location, bool flag);		// constructor
                ~Lane();				//destructor
                Car *get_head();			// get the head pointer
                void set_head(Car *car);		//set the head pointer
                int get_location();			// get the location information
		bool get_sl_pass();			//get the information if stoplight can allow the car pass

                void addCar(Car *car);			// add the car in the lane
        protected:
                Car *head;		//head pointer
                stoplight light;
};
#endif
                                                                                                                                              location.h                                                                                          000644  000765  000024  00000000720 13361703002 013243  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes



#ifndef location_h
#define location_h
class Location					//Base class
{
        public:
                Location();			//constructor
                Location(int loca);		//constructor
                ~Location();    		//destructor
		/*map *get_map(){
			return Map;
		}*/
        protected:
                int location;	
		//map * Map;
};
#endif
                                                map.h                                                                                               000644  000765  000024  00000001365 13361743645 012237  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         //Jianqiang Hao
//CS202
//Prog1
//10/17/18
//using object oriented proggramming to
//simulate the car in the lanes



#ifndef map_h
#define map_h
#include "lane.h"
#include "car.h"
class Lane;
class map							//class map
{
        public:
                map(int size);					//constructor
                ~map();						//destructor
                void addCar(Car *my_car);			//add a car in the map;
                void display();					//display all information in the map
                void display_car(Car *head);			//display car's information in a lane
		void move_car(int location, Car *instance);	// move the car to other lanes
        private:
                int lane_size;					//the number of lanes in the map
                Lane **list;
};
#endif
                                                                                                                                                                                                                                                                           stoplight.h                                                                                         000644  000765  000024  00000000357 13361537330 013467  0                                                                                                    ustar 00Hardy                           staff                           000000  000000                                                                                                                                                                         #ifndef stoplight_h
#define stoplight_h
class stoplight
{
        public :
                stoplight(bool flag);
                ~stoplight();
		bool get_pass(){
			return pass;
		}

        protected:
                bool pass;
};
#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
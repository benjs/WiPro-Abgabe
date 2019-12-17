/*
 * MyFunctions.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */

#include <cmath>
#include <iostream>
#include "MyFunctions.h"

using namespace std;

MyQuaternion quaternion_rotation(double x,double y,double z,double const theta){

  // Quellcode implememtieren

  
}

MyQuaternion rotateX(MyQuaternion const &X,MyQuaternion const &Q){
  // Quellcode implementieren: und auch in Aufgabe3 einfügen
}


/*
 *  vorgegeben:
 *
 */
void Qprint(const MyQuaternion &Q,const std::string txt=""){
	cout<<txt<<"("<<Q[0]<<","<<Q[1]<<","<<Q[2]<<","<<Q[3]<<")"<<endl;
}


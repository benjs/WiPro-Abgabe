/*
 * MyFunctions.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */

#include <cmath>
#include <iostream>
#include "MyFunctions.h"

MyQuaternion quaternion_rotation(double x,double y,double z,double const theta){
  // Quellcode implememtieren
  double rad = theta/180*M_PI;
  return MyQuaternion(x*sin(rad/2), y*sin(rad/2), z*sin(rad/2), cos(rad/2));
}

MyQuaternion rotateX(MyQuaternion const &X,MyQuaternion const &Q){
  // Quellcode implementieren: und auch in Aufgabe3 einfügen
  MyQuaternion Q1 = Q; // Mit der geforderten implementierung von MyQuaternion kann man keine Multiplikation von zwei konstanten Objekten durchführen!
  return Q1*X*Q1.conj();
}


/*
 *  vorgegeben:
 *
 */
void Qprint(const MyQuaternion &Q,const std::string txt=""){
	std::cout<<txt<<"("<<Q[0]<<","<<Q[1]<<","<<Q[2]<<","<<Q[3]<<")"<<std::endl;
}


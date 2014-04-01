/*
 * temperatureCluster.hpp
 *
 *  Created on: 18 mars 2014
 *      Author: SESA188919
 */

#ifndef TEMPERATURECLUSTER_HPP_
#define TEMPERATURECLUSTER_HPP_


#include "temperatureCluster.adl.hpp"

using namespace __ns_temperatureCluster;

class temperatureCluster: public temperatureClusterDefinition {
protected:
public:
	virtual unsigned char getDirection();

	virtual unsigned short getClusterID();

	virtual unsigned char serialize(unsigned char* a_iSize, unsigned char* a_pBuffer);

	virtual unsigned char deserialize(unsigned char a_iInSize, unsigned char* a_pInBuffer, unsigned char* a_iOutSize, unsigned char* a_pOutBuffer);

	virtual unsigned char update();
};





#endif /* TEMPERATURECLUSTER_HPP_ */

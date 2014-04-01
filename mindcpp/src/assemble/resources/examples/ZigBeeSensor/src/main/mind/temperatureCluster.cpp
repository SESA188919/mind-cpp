#include <stdio.h>
#include "temperatureCluster.hpp"

// -----------------------------------------------------------------------------
// Implementation of the primitive temperatureCluster.
// -----------------------------------------------------------------------------

/*
 * @fn void Init()
 * @brief Initialize the cluster
 */
void cluster::Init() {
	PRIVATE.attribute_measured_value = 0x00;
	PRIVATE.attribute_max_value = 0x01;
	PRIVATE.attribute_min_value = 0x02;
	PRIVATE.data_type = 0x21;
}

/*
 * @fn uint8 getDirection()
 * @brief Return the type of cluster (input = server; output = client)
 * @return clusterID 0 = output cluster; 1 = input cluster; 2 = input and ouput
 */
unsigned char cluster::getDirection() {
	return 0;
}

/*
 * @fn uint16 getClusterID()
 * @brief Get the cluster ID
 * @return clusterID The cluster ID
 */
unsigned short cluster::getClusterID() {
	return 0;
}

/*
 * @fn uint8 serialize(uint8* a_iSize, uint8 * a_pBuffer)
 * @brief Get the serialized buffer ready to send
 * @param a_isize The buffer size
 * @param a_pbuffer The buffer
 * @return result The result of the operation (0 = success, !=1 failed)
 */
unsigned char cluster::serialize(unsigned char* a_iSize, unsigned char * a_pBuffer) {
	signed short data;

	sensoritf.switchOn();
	temperatureitf.GetCurrentTemperature(&data);
	sensoritf.switchOff();

	a_pBuffer[0] = PRIVATE.attribute_measured_value >> 8;
	a_pBuffer[1] = PRIVATE.attribute_measured_value;
	a_pBuffer[2] = PRIVATE.data_type;
	a_pBuffer[3] = data;
	a_pBuffer[4] = data >> 8;

	*a_iSize+= 5;

	return 0;
}

/*
 * @fn uint8 deserialize(uint8 a_iInSize, uint8* a_pInBuffer, uint8* a_iOutSize, uint8* a_pOutBuffer)
 * @brief Deserialized an input buffer
 * @param a_isize The buffer size
 * @param a_pbuffer The buffer
 * @return result The result of the operation (0 = success, !=1 failed)
 */
unsigned char cluster::deserialize(unsigned char a_iInSize, unsigned char* a_pInBuffer, unsigned char* a_iOutSize, unsigned char* a_pOutBuffer) {
	return 0;
}

/**
 * @fn uint8 update()
 * @brief update the cluster
 * @return The result of the operation (0 = success, !=1 failed)
 */
unsigned char cluster::update() {
	return 0;
}

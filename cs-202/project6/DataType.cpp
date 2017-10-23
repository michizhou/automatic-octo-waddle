#include <iostream>

#include "DataType.h"

DataType::DataType(){
	m_intVal = 0;
	m_doubleVal = 0.0;
}

DataType::DataType(int intVal, double doubleVal){
	m_intVal = intVal;
	m_doubleVal = doubleVal;
}

bool DataType::operator==(const DataType& other_dataType) const{
	return m_intVal==other_dataType.m_intVal && m_doubleVal==other_dataType.m_doubleVal;
}

DataType& DataType::operator=(const DataType& other_dataType){
	m_intVal = other_dataType.m_intVal;
	m_doubleVal = other_dataType.m_doubleVal;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const DataType& dataType){
	os << "{" << dataType.m_intVal << "," << dataType.m_doubleVal << "}";
	return os;
}

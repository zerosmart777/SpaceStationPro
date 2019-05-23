#include "pch.h"
#include <iostream>
#include "SpaceStation.hpp"
#include "Robot.hpp"

SpaceStation::SpaceStation()
	:m_posX(0), m_posY(0), m_posZ(0), roId(20)
{
}

SpaceStation::SpaceStation(const SpaceStation &_s)
	: m_posX(_s.m_posX), m_posY(_s.m_posY), m_posZ(_s.m_posZ), roId(_s.roId)
{
}

SpaceStation::~SpaceStation()
{
}

SpaceStation& SpaceStation::operator = (const SpaceStation &_s)
{
	m_posX = _s.m_posX;
	m_posY = _s.m_posY;
	m_posZ = _s.m_posZ;
	roId = _s.roId;
	return *this;
}

void SpaceStation::init()
{
	m_robot = std::make_shared<std::vector<Robot>>();
	int nCount = 0;
	while (nCount < roId) {
		m_robot->push_back(Robot(nCount));
		nCount++;
	}

	// shared_from_this requires the object to exist, so
	// it cannot use within intializer.
	int nCount2 = 0;
	while (nCount2 < roId) {
		m_robot->at(nCount2).setStation(shared_from_this());
		nCount2++;
	}
}


void SpaceStation::printStatus() const
{
	std::cout << "\nReport Position" << std::endl;
	std::cout << "x = "<< m_posX << ", y =  " << m_posY << ", z = " << m_posZ << std::endl;
}


std::weak_ptr<std::vector<Robot>> SpaceStation::getRobot() const
{
	return m_robot;
}

float SpaceStation::getPositionX() const {
	return m_posX;
}

float SpaceStation::getPositionY() const {
	return m_posY;
}

float SpaceStation::getPositionZ() const {
	return m_posZ;
}

void SpaceStation::setPositionX(float _posX) {
	m_posX = _posX;
}

void SpaceStation::setPositionY(float _posY) {
	m_posY = _posY;
}

void SpaceStation::setPositionZ(float _posZ) {
	m_posZ = _posZ;
}
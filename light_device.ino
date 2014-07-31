#include "light_device.h"
#include "config.h"

LightDevice::LightDevice()
    : m_lightState(LIGHT_IDLE)
{}

void LightDevice::init()
{
    pinMode(LIGHT_CONTROL_PIN, OUTPUT);
}

void LightDevice::lightUp()
{
    digitalWrite(LIGHT_CONTROL_PIN, HIGH);
    m_lightState = LIGHT_IDLE;
}

void LightDevice::lightDown()
{
    digitalWrite(LIGHT_CONTROL_PIN, LOW);
    m_lightState = LIGHT_IDLE;
}

void LightDevice::step()
{
    switch(m_lightState)
    {
    case LIGHT_UP:
        lightUp();
        break;
    case LIGHT_DOWN:
        lightDown();
        break;
    case LIGHT_IDLE:
        break;
    }
}

void LightDevice::notify()
{
    switch(noti->type)
    {
    case NOTI_EVENT_COMMING:
        m_lightState = LIGHT_UP;
        break;
    case NOTI_ERROR:
    case NOTI_SKIP_EVENT:
        m_lightState = LIGHT_DOWN;
        break;
    }
}

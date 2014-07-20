#ifndef __SMART_ALARM_LINK_LIST_H__
#define __SMART_ALARM_LINK_LIST_H__

class IDevice;
class DeviceNode;

class DeviceList
{
private:
    DeviceNode* m_head;
    DeviceNode* m_tail;
public:
    DeviceList();
    ~DeviceList();
    void add(DeviceNode*);
    DeviceNode* head();
};

class DeviceNode
{
private:
    DeviceNode* m_next;
    IDevice* m_device;
public:
    DeviceNode(IDevice*);
    ~DeviceNode();
    DeviceNode* next();
    IDevice* device();
    friend class DeviceList;
};

#endif

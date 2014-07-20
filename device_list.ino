#include <stdlib.h>
#include "device_list.h"
#include "device.h"

// Class DeviceList

DeviceList::DeviceList()
{
    m_head = NULL;
}

DeviceList::~DeviceList()
{
    DeviceNode* tmpNode;
    while(tmpNode = m_head)
    {
        m_head = m_head->m_next;
        delete tmpNode;
    }
}

void DeviceList::add(DeviceNode* node)
{
    if (m_head)
    {
        node->m_next = m_head;
        m_head = node;
    }
    else
    {
        m_head = node;
        node->m_next = NULL;
    }
}

DeviceNode* DeviceList::head()
{
    return m_head;
}

// Class DeviceNode

DeviceNode::DeviceNode(IDevice* device)
{
    m_device = device;
}

DeviceNode::~DeviceNode()
{
    delete m_device;
}

DeviceNode* DeviceNode::next()
{
    return m_next;
}

IDevice* DeviceNode::device()
{
    return m_device;
}


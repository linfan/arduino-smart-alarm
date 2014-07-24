#include "device_list.h"
#include "assert.h"

TEST_CASE_FILE

// Mock
class IDevice
{
private:
    int fake_data;
public:
    IDevice(int data) { fake_data = data; }
    int getFakeData() { return fake_data; }
};

void test_device_list()
{
    TEST_CASE_BEGIN

    int num[] = {125, 360, 2048};
    int i, size = sizeof(num)/sizeof(int);
    DeviceList* list = new DeviceList;
    for (i = 0; i < size; ++i)
        list->add(new DeviceNode(new IDevice(num[i])));
    i = size - 1;
    DeviceNode* node = list->head();
    do {
        Assert::equal(node->device()->getFakeData(), num[i]);
        --i;
    } while(node = node->next());
    delete list;
}


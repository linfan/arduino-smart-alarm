#include "device_list.h"
#include "assert.h"

// Mock
class IDevice
{
private:
    int fake_data;
public:
    IDevice(int data) { fake_data = data; }
    int getFakeData() { return fake_data; }
};

int main()
{
    TEST_CASE_BEGIN
    int num[] = {125, 360};
    int i, size = sizeof(num)/sizeof(int);
    DeviceList* list = new DeviceList;
    for (i = 0; i < size; ++i)
        list->add(new DeviceNode(new IDevice(num[i])));
    i = size - 1;
    DeviceNode* tmpNode = list->head();
    do {
        assert_equal(tmpNode->device()->getFakeData(), num[i]);
        --i;
    } while(tmpNode = tmpNode->next());
    delete list;
}

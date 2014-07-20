all: test_device_list test_json_parser test_clock

clean:
	ls | grep '^test_' | grep -v '.*\.cc' | xargs rm -f

run:
	for file in `ls | grep '^test_' | grep -v '.*\.cc'`; do ./$$file; done

test_device_list: test_device_list.cc ../device_list.ino
	g++ -o $@ -I.. -Wno-parentheses -Wno-delete-non-virtual-dtor -x c++ $^

test_clock: test_clock.cc ../clock.ino
	g++ -o $@ -I.. -Wno-parentheses -Wno-delete-non-virtual-dtor -x c++ $^

test_json_parser: test_json_parser.cc ../device_list.ino
	g++ -o $@ -I.. -Wno-parentheses -Wno-delete-non-virtual-dtor -x c++ $^

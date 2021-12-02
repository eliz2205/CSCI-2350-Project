target = Driver
sources = Hourly.cpp Piecework.cpp Salary.cpp Driver.cpp EmployeeFactory.cpp EmployeeFile.cpp Commission.cpp
objects = $(sources:.cpp=.o)
headers = Employee.h Salary.h Hourly.h Piecework.h EmployeeFactory.h EmployeeFile.h Commission.h

cc = g++
cflags = -c -Wall -std=c++17

all: $(target)

$(target): $(objects)
	$(cc) $(objects) -o $(target)

$(objects): $(sources) $(headers)
	$(cc) $(cflags) $(sources)

tar:
	rm -f $(objects) $(target)
	tar cvf $(target).tar.gz *

clean:
	rm -f $(objects) $(target)


// ����� ���������
// ����� ����������

#include "Flight.h"
#include <regex>

void initFlights();
void showMenu();
int readChoice();
void showFlightCodes();
int getFlightByCode(string);
string readString();
Passenger requestPassengerInformation();
bool isInteger(string);
bool isDouble(string);
void reserveSeat(Flight, int, bool);
void reserveSeat(Flight, int, Passenger, bool);
void showSingleFlightMenu();
void showMultipleFlightMenu();
void showAddFlightMenu();
void showRemoveFlightMenu();
void showFlightCancelReservationMenu();

// ������������ ��� ������ ������� ��� ����������.
LinearList<Flight> flights(100);

int main()
{
	// �������� ������� ������� �������.
	initFlights();

	// ��������� �� ����� ��� ��������� ��� ������ ��� ����� ����� � ������� �� ������� �� ���������.
	while (true)
	{
		showMenu();

		// ����������� ��� ��� ������ ��� ������� ��� �� 1 ��� �� 5 ��� ����������� �� ��������� �����.

		int choice = readChoice();

		if (choice == 1)
		{
			showSingleFlightMenu();
		}
		else if (choice == 2)
		{
			showMultipleFlightMenu();
		}
		else if (choice == 3)
		{
			showAddFlightMenu();
		}
		else if (choice == 4)
		{
			showRemoveFlightMenu();
		}
		else
		{
			showFlightCancelReservationMenu();
		}

		cout << endl;
	}

	system("pause");
	return 0;
}

void initFlights()
{
	// ������������ �������: �����, �����������, �����.

	// ������ ��� ������� ����� ��� ����������� �� �����,
	// � ������� ������ �� ������� ���� ����� ��� �� �������� ��� ����� ��� ����.

	flights.insert(0, Flight("THE1",	"Athens",		"Thessaloniki",		Time(10), Time(12), 20.0, "Type1",	100,	0));
	flights.insert(1, Flight("THE2",	"Athens",		"Thessaloniki",		Time(14), Time(16), 20.0, "Type2",	1,		1));

	flights.insert(2, Flight("PAT1",	"Athens",		"Patra",			Time(16), Time(17), 10.0, "Type1",	1,		0));
	flights.insert(3, Flight("PAT2",	"Athens",		"Patra",			Time(20), Time(21), 10.0, "Type1",	1,		0));

	flights.insert(4, Flight("ATH1",	"Thessaloniki", "Athens",			Time(14), Time(16), 15.0, "Type3",	1,		0));
	flights.insert(5, Flight("ATH2",	"Thessaloniki", "Athens",			Time(18), Time(20), 15.0, "Type3",	1,		0));

	flights.insert(6, Flight("ATH3",	"Patra",		"Athens",			Time(19), Time(20), 15.0, "Type3",	1,		0));
	flights.insert(7, Flight("ATH4",	"Patra",		"Athens",			Time(22), Time(23), 15.0, "Type3",	1,		0));
}

void showMenu()
{
	cout << "Ticket System" << endl;
	cout << "Type the number of your choice." << endl << endl;

	cout << "1. Select an existing flight." << endl;
	cout << "2. Select a list of flights." << endl;
	cout << "3. Add a new flight route." << endl;
	cout << "4. Remove an existing flight route." << endl;
	cout << "5. Cancel a flight reservation." << endl;
}

int readChoice()
{
	// ������� �������� ����� ��� ������, �� ��������� ��� ������� ���� �����
	// ��� �� 1, 2, 3, 4, 5, 6 ����������� ������ ������ ��� ������������ �������.

	string input = "";

	cout << "> ";
	cin >> input;

	while (input.find_first_not_of("123456") != string::npos)
	{
		cout << "Invalid input, please enter a valid number." << endl;
		cout << "> ";
		cin >> input;
	}

	return stoi(input);
}

string readString()
{
	cout << "> ";
	string input;
	cin >> input;
	return input;
}

void showFlightCodes()
{
	cout << endl << "Flight routes: " << endl;
	flights.output(cout);
}

int getFlightByCode(string code)
{
	// ������� ��� ������� ������ ��� �������� � �������.
	// ������� �� index ��� ������ ��� ����� flights ���� �� ������� �� ����������� Flight.

	Flight flight;
	int flightIndex = 0;

	for (int i = 1; i <= flights.length(); i++)
	{
		// ��������� �� � ������� ������ ����������� �� ������ ����� ��� �����.

		flights.find(i, flight);

		if (flight.getCode() == code)
		{
			flightIndex = i;
			break;
		}
	}

	// �� ��������� ��� ��� ������ ��� ����� flights � ��������� ���������� 0.
	return flightIndex;
}

Passenger requestPassengerInformation()
{
	// ������� �� �������� ��� �������, �������:
	// - �����					string
	// - �������				string
	// - ������� �����������	int
	// - ����������				string
	// - ���������				string
	// - ��������				int

	// �� �� ��������� isInteger() ��������� �� � ������� ����������� ��� �� �������� ����� �������.

	cout << endl << "Please enter your passenger information." << endl;

	string firstname;
	cout << "First name: ";
	cin >> firstname;

	string lastname;
	cout << "Last name: ";
	cin >> lastname;

	string passportNumber;

	do
	{
		cout << "Passport number: ";
		cin >> passportNumber;
	} while (!isInteger(passportNumber));

	string nationality;
	cout << "Nationality: ";
	cin >> nationality;

	// ������ � ��������� ������ �� �������� ����, ������� ��� getline() ���� ������� cin.ignore().
	string address;
	cout << "Address: ";
	cin.ignore();
	getline(cin, address);

	string telephone;

	do
	{
		cout << "Telephone: ";
		cin >> telephone;
	} while (!isInteger(telephone));

	// ��������� ��� ��������� ������������ Passenger.

	Passenger passenger(firstname, lastname, stoi(passportNumber), nationality, address, stoi(telephone));
	return passenger;
}

bool isInteger(string x)
{
	// ������� string ��� �������� ���������� ��� 0-9 ����� ���� ��������.
	return regex_match(x, regex("^[0-9]{1,}"));
}

bool isDouble(string x)
{
	// ������� string ��� �������� ���������� ��� 0-9 ��� ����� �����, ������ ��� �� ������� ����� ���� �� �����.
	// �� �������� ����� ����� �����������.
	return regex_match(x, regex("^[0-9]{1,}\.?[0-9]{1,}$"));
}

bool isTime(string x)
{
	// ������� string ��� �������� ��� ���������� ��� 0-9 ��� ����� �����, ��� ��� ���� ������ ��� �� ������� ����� ���� �� �����.
	return regex_match(x, regex("^[0-9]{2}\:[0-9]{2}$"));
}

void reserveSeat(Flight flight, int flightIndex, bool alwaysQueue = false)
{
	// �������� ��� ������ �������� � ��� ���� ��� ������������ flight.
	// � ���������� flightIndex ���������� �� index ��� flight ��� ����� flights.
	// � ���������� alwaysQueue ���������� �� ������� � �������� �� ������� ����� ���� ����.

	Passenger passenger = requestPassengerInformation();

	// ��� ������� �� ������ ���� ������� ������ ����� ���� ���� �����.
	while (flight.hasPassenger(passenger))
	{
		cout << "Passenger has already reserved a seat on that flight." << endl;
		passenger = requestPassengerInformation();
	}

	cout << endl;

	// ������� ��� ������� ������ ��� ���������� ���� ������ �� ����������� passenger.
	reserveSeat(flight, flightIndex, passenger, alwaysQueue);
}

void reserveSeat(Flight flight, int flightIndex, Passenger passenger, bool alwaysQueue = false)
{
	// �� ��� ���������� ��� ������ ����������� passenger ���� �� ����������� ��� ����� �������� � ��� ���� ��� ������������ flight.
	// ������ ��� �����������, �� � ����� ����� ������ ���� ����������� ��� passenger �� �������.
	// �� � ����� ���� ���������� ������ ���� ����������� ��� passenger ��� ����� ��������.

	if (alwaysQueue || flight.isFull())
	{
		LinkedQueue<Passenger> queue = flight.getQueue();
		queue + passenger;
		flight.setQueue(queue);

		cout << "All seats are reserved, your position in queue is #" << queue.length() << "." << endl;
	}
	else
	{
		LinearList<Passenger> passengers = flight.getPassengers();
		passengers.insert(passenger);
		flight.setPassengers(passengers);

		cout << "Airplane seat available, you have reserved seat #" << flight.getReservations() << "." << endl;
	}

	// ������ ������ ��������� ��� ������� ������, ����������� ��� ����� �� ��� ������������� �����.
	flights.replace(flightIndex - 1, flight);
}

void showSingleFlightMenu()
{
	// � ������� �������� ��� ������������ �����, ���������� ��� ������ ���.

	cout << endl << "Enter a single flight by it's code." << endl;

	showFlightCodes();

	string code = readString();

	// �� � ������� ����� end ����������� ���.
	if (code == "end") return;

	// ������� ��� index ���� �� ������������� ��� ������� � �����.
	int flightIndex = getFlightByCode(code);

	while (flightIndex == 0)
	{
		cout << "Invalid flight code, please try again." << endl;
		code = readString();
		
		// ��� ����� ����� � �������, ���� ��������� �� ����������� ���.
		if (code == "end") return;

		flightIndex = getFlightByCode(code);
	}

	// �������� ����� ��� �����.

	Flight flight;
	flights.find(flightIndex, flight);

	reserveSeat(flight, flightIndex);
}

void showMultipleFlightMenu()
{
	// � ������� ������� ������� ���� �����, ���������� ��� ������ ����.

	cout << endl << "Enter a list of flights by their code." << endl;
	cout << "Type 'end' to stop entering flight codes." << endl;

	showFlightCodes();

	LinearList<Flight> flightRoute(100); // � ����� �� �� �������� ������� ��� ������.
	LinearList<int> flightIndexes(100); // � ����� �� �� indexes ��� ������� ��� flights.

	for (int i = 1; i <= 100; i++)
	{
		string code = readString();

		//  �� � ������� ����� end ����������� ���.
		if (code == "end") break;

		// ������� ��� index ���� �� ������������� ��� ������� � �����.
		int flightIndex = getFlightByCode(code);

		while (flightIndex == 0)
		{
			cout << "Invalid flight code, please try again." << endl;
			code = readString();

			// ��� ����� ����� � �������, ���� ��������� �� ����������� ���.
			if (code == "end") break;

			flightIndex = getFlightByCode(code);
		}

		// �� � ������� ���� ����� ��� ������ ������ end ���� ��� ����������� while, ������ �� ������ ��� ��� �� ������ loop.
		if (code == "end") break;

		Flight currentFlight;
		flights.find(getFlightByCode(code), currentFlight);

		if (i == 1)
		{
			// �������� ��� ������ ������ ��� �������� ����� ������ ���� ��� ������� �����������.

			flightRoute.insert(i - 1, currentFlight);
			flightIndexes.insert(i - 1, flightIndex);
		}
		else
		{
			// ������� ��� ������ ��� ������� ���� ��� �����.

			Flight previousFlight;
			flightRoute.find(i - 1, previousFlight);

			while (!previousFlight.isInOrderWith(currentFlight))
			{
				cout << "Invalid flight order, please try again." << endl;
				code = readString();

				// ���� ��� ���� �� ������ ���� end ��������� ��� �� while.
				if (code == "end") break;

				flightIndex = getFlightByCode(code);

				while (flightIndex == 0)
				{
					cout << "Invalid flight code, please try again." << endl;
					code = readString();

					// �� � ������� ����� ����� ���, ��������� ���� ��� �� while.
					if (code == "end") break;

					flightIndex = getFlightByCode(code);
				}

				// �� � ������� ���� ����� ��� ����������� while, ��������� ��� �� ������ while.
				if (code == "end") break;

				// �������� ��� ������ ���� �� ��������� �� � ���������� ����� ������ �����.
				flights.find(flightIndex, currentFlight);
			}

			// �� � ������� ���� end ��� ����������� while, ��������� ��� �� ������ loop.
			if (code == "end") break;

			// �� ��� ����� ���� ���� ��� ������, ��������� ��� ����� ��� ��������.
			flightRoute.insert(i - 1, currentFlight);
			flightIndexes.insert(i - 1, flightIndex);
		}
	}

	// �� � ������� �������� ������ ��� ��������, ��� ����������� ��� ������ �� �������� ���.
	if (!flightRoute.isEmpty())
	{
		cout << endl << "Your route: " << endl;

		for (int i = 1; i <= flightRoute.length(); i++)
		{
			Flight flight;
			flightRoute.find(i, flight);

			// �� ����������� ��� ��� ���� ��� ��� ��������� ��� ������ ������.
			if (i == 1)
				cout << flight.getOrigin() << " -> " << flight.getDestination();
			// ������ ���� ��� ��������� ������ � ���� ��� �� ����� � ���������� ��� ������������.
			else
				cout << flight.getDestination();

			// �� ��� ����� � ��������� �����, ����������� ������� ��������� ���� ������.
			if (i != flightRoute.length()) cout << " -> ";
		}

		cout << endl;
		
		// ������ ��� �������� ��� ��������� ��� �������.

		Passenger passenger = requestPassengerInformation();
		bool queueFound = false;

		for (int i = 1; i <= flightRoute.length(); i++)
		{
			Flight flight;
			flightRoute.find(i, flight);

			// ��������� �� � �������� ����� ��� ��� ����� � ���� ���� ��������.
			while (flight.hasPassenger(passenger))
			{
				cout << "Passenger has already reserved a seat in one of those flights or is waiting in the queue." << endl;
				passenger = requestPassengerInformation();
			}

			if (i == 1) cout << endl;

			// �� ��� ��� ��� ������� ����� ������ ���� �� ����������� � �������� ���� ����� �������� ���� ��� ������� ��� ���������.

			if (flight.isFull() && !queueFound) queueFound = true;

			cout << flight.getCode() << ". ";
			
			int flightIndex;
			flightIndexes.find(i, flightIndex);

			reserveSeat(flight, flightIndex, passenger, queueFound);
		}
	}
}

void showAddFlightMenu()
{
	// �������� ���� ������ ��� �������.
	// ��� �� ��� ����� �������:
	// - ������					string
	// - ����					string
	// - ���������				string
	// - ��� ����������			Time
	// - ��� ������				Time
	// - ����� ����������		string
	// - ���� ����������		double
	// - ������ ����������		int

	cout << endl << "Enter the flight details." << endl;

	string code;
	cout << "Code (eg. TH1): ";
	cin >> code;

	// � ���� ��� � ���������� ������ �� ��������� ����, ����� �������������� �� getline().

	string origin;
	cout << "Origin: ";
	cin.ignore();
	getline(cin, origin);

	string destination;
	cout << "Destination: ";

	getline(cin, destination);

	// �� ���� ������� �� ����� ��� ������ ��:�� ���� � ��� 0-9.
	// ����� ��� ���������� isTime().

	string departureTime;

	do
	{
		cout << "Departure Time (eg. 14:20): ";
		cin >> departureTime;
	} while (!isTime(departureTime));

	string arrivalTime;

	do
	{
		cout << "Arrival Time (eg. 17:20): ";
		cin >> arrivalTime;
	} while (!isTime(arrivalTime));

	string airplaneType;
	cout << "Airplane Type: ";
	cin >> airplaneType;

	// � ���� ������� �� ����� double.
	// ����� ��� ���������� isDouble().

	string ticketPrice;

	do
	{
		cout << "Ticket Price: ";
		cin >> ticketPrice;
	} while (!isDouble(ticketPrice));

	// �� ������ ������� �� ����� int.
	// ����� ��� ���������� isInteger().

	string airplaneSeats;

	do
	{
		cout << "Airplane Seats: ";
		cin >> airplaneSeats;
	} while (!isInteger(airplaneSeats));

	// ����������� ��� ���� ��� �� ����� ��� ��� ������������ ��� string �� int.
	int departureHour = stoi(string(departureTime.c_str(), departureTime.c_str() + 2));
	int departureMinute = stoi(string(departureTime.c_str() + 3, departureTime.c_str() + 5));
	int arrivalHour = stoi(string(arrivalTime.c_str(), arrivalTime.c_str() + 2));
	int arrivalMinute = stoi(string(arrivalTime.c_str() + 3, arrivalTime.c_str() + 5));

	// ������������ ��� ���� ���������� ��� ��� ������ ��� ������������ �� double ��� int ����������.
	double parsedTicketPrice = atof(ticketPrice.c_str());
	int parsedAirplaneSeats = atoi(airplaneSeats.c_str());

	// ��������� ��� �������� ��� flights ��� ���� ������������ flight.
	Flight flight(code, origin, destination, Time(departureHour, departureMinute), Time(arrivalHour, arrivalMinute), parsedTicketPrice, airplaneType, parsedAirplaneSeats, 0);
	flights.insert(flight);

	cout << endl << "Successfully created flight " << flight.getCode() << "." << endl;
}

void showRemoveFlightMenu()
{
	// �������� ������ �� �������� �������.

	showFlightCodes();

	// ��� ������� �� ������� �� ���� ����� �����, ����� ������ �� ���� ����������� ���.

	if (flights.length() <= 1)
	{
		cout << endl << "This feature is not available, the system must have at least 2 flight routes." << endl;
	}
	else
	{
		cout << endl << "Enter the code of the flight you want to remove." << endl << endl;

		// ������� ����������� ��� �������, �� ����� end ���� ���������.

		string code = readString();

		if (code == "end") return;

		int flightIndex = getFlightByCode(code);

		while (flightIndex == 0)
		{
			cout << "Invalid flight code, please try again." << endl;
			code = readString();

			if (code == "end") return;

			flightIndex = getFlightByCode(code);
		}

		// ������ ��� �������� ��� ������ ��� �� ����� flights.

		Flight flight;
		flights.find(flightIndex, flight);
		flights.remove(flightIndex, flight);

		cout << endl << "Flight " << flight.getCode() << " has been removed." << endl;
	}
}

void showFlightCancelReservationMenu()
{
	// �������� ����������� ��� ���������� �������� ������� �������.
	// ������ ���� �� �����, ������� ��� ��� ������ ����������� (�� "��������� ������").

	cout << endl << "Enter your full name and passport number." << endl;

	cout << "First Name: ";
	string firstname;
	cin >> firstname;

	cout << "Last Name: ";
	string lastname;
	cin >> lastname;

	cout << "Passport Number: ";
	string passportNumber;
	cin >> passportNumber;

	cout << endl;

	// ��������� ���������� ������������ ��� ��� ���������.
	Passenger passenger(firstname, lastname, stoi(passportNumber), "", "", 0);

	// �� ����� true ���� � �������� ����� �� ��� ����������� �����.
	bool found = false;

	// ��������� �� ���� ��� ������� ��� ����������.
	for (int i = 1; i <= flights.length(); i++)
	{
		Flight flight;
		flights.find(i, flight);

		bool inFlight = flight.getPassengers().search(passenger) != 0;
		bool inQueue = flight.getQueue().search(passenger);
		
		if (!found)
			found = inFlight || inQueue;

		// �������� ���� ��� ������� ��� �������.
		if (inFlight || inQueue)
		{
			if (inQueue) cout << "(QUEUED) "; // �� ����� ���� ���� ���� ����������� ���� �� �������.

			flight.output(cout);
			cout << endl;
		}
	}

	// �� ������ ������ ������� ���� ����������� ���� ������� ��������� ���� �� ������ ������.

	if (found)
	{
		// �� true ���� � ������� ��� �������� � ������ ����������� �� ����� ��� ����� �������� � ����� ���� ����.
		bool validFlight = false;

		// ������� �����������, �� � ������� ����� end ���� ���������.
		cout << endl << "Enter the code of the flight you want to cancel." << endl;

		while (!validFlight)
		{
			string code = readString();

			if (code == "end") break;

			int flightIndex = getFlightByCode(code);

			while (flightIndex == 0)
			{
				cout << "Invalid flight code, please try again." << endl;
				code = readString();

				if (code == "end") break;

				flightIndex = getFlightByCode(code);
			}

			if (code == "end") break;

			Flight flight;
			flights.find(flightIndex, flight);

			// ��������� �� ����� ��� ����� �������� � ���� ���� ��������.

			int passengerIndex = flight.getPassengers().search(passenger);
			bool inQueue = flight.getQueue().search(passenger);

			if (passengerIndex != 0 || inQueue)
			{
				// �� ����� �������� ���� ��� ��������� ��� �� �����.
				if (passengerIndex)
				{
					LinearList<Passenger> passengers = flight.getPassengers();
					passengers.remove(passengerIndex, passenger);

					// �� � ��� ����� �������� ����� ��������� ��� ��� ������ ���� �������� ������ ��� ���������.
					if (passengers.length() <= flight.getPassengers().length())
					{
						// ��� � ����������� ���� ���� ������ �� ���� ����, ����� ������� ��� ��� ����� ��������.
						LinkedQueue<Passenger> queue = flight.getQueue();
						Passenger first;
						queue - first;
						
						passengers.insert(first);
						flight.setQueue(queue);
					}

					// ��������� ��� ������ �������� ��� ������.
					flight.setPassengers(passengers);
				}
				// ����������� �� ����� ���� ���� ���� ��� ���������.
				else
				{
					// �������������� ��� ��� ���� ����� ��� ������ ��� ����������.
					LinkedQueue<Passenger> queue = flight.getQueue();
					LinkedQueue<Passenger> newQueue;
					Passenger first;

					while (!queue.isEmpty())
					{
						queue - first;
						if (first != passenger) newQueue + first;
					}

					flight.setQueue(newQueue);
				}

				// �������� ��� ����� flighs.
				flights.replace(flightIndex - 1, flight);

				cout << "Passenger removed from flight " << flight.getCode() << "." << endl;
				break;
			}
			else
			{
				cout << "Passenger hasn't selected this flight, please try again." << endl;
			}
		}
	}
	else
	{
		cout << endl << "No associated flights were found." << endl;
	}
}
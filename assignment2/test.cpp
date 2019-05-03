#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

int main(void)
{
	/*txt에서 정보 불러오기*/
	ifstream fin("flight_time.txt");
	vector<string> input;
	string s;
	if (!fin.is_open()) {
		cout << "failed file read" << endl;
		return 0;
	}

	cout << "flight_time.txt"<<endl;

	while (!fin.eof())
	{
		getline(fin,s);
		cout << s << endl;
		input.push_back(s);
	}
	
	cout << "----------------------------" << endl;

	/*pair에 시간, 목적지 저장*/
	vector<pair <string, int> > info;

	for (int i = 0; i < input.size(); i++) {
		string a;
		string b;
		int dutime;
		for (int j = 0; j < input[i].length(); j++) {
			
			if (97 <= input[i][j] && input[i][j] <= 122) {
				a += input[i][j];
			}
			if (65 <= input[i][j] && input[i][j] <= 90) {
				a += input[i][j];
			}
			if (48<=input[i][j]&&input[i][j]<=57)
			{
				b += input[i][j];
			}
		}
		
		dutime = stoi(b);
		pair<string,int>p;
		p = make_pair(a, dutime);

		info.push_back(p);

	}
	
	/*for (int i = 0; i < data.size(); i++)
		cout << data[i].first <<' '<< data[i].second << endl;*/

	/*시간 계산*/ 
	string date; //2019/04/05
	string dtime; //23:59
	string dest; //Tokyo
	
	cout<< "- Input form users"<<endl;
	cout<<"Departure data : ";
	cin>>date;
	cout<<"Departure time : ";
	cin>>dtime ;
	cout<<"Destination : ";
	cin>>dest;
	cout << endl;

		/*1)도착 날짜 계산*/
	
		string temp;

		for (int i = 8; i <10; i++) {
			temp += date[i];
		}

		int arvdate = stoi(temp);
		/*cout << departure_date_new << endl;*/

	

		/*2) 도착시간 계산*/
		int minute;
		int hour;
		string a;

		for (int i = 0; i <= 1; i++)
			a += dtime[i];

		hour = stoi(a);

		string b;

		for (int i = 3; i <= 4; i++)
			b += dtime[i];

		minute = stoi(b);

		/*cout << departure_hour << ' ' << departure_minute << endl;*/

		int atime;

		for (int i = 0; i < info.size(); i++)
		{
			if (dest == info[i].first)
				atime = info[i].second;
		}

		int bt_hour = atime / 60;
		int bt_minute = atime % 60;

		hour += bt_hour;
		int flag = 0;
		if (hour > 24) {
			hour -= 24;
			flag = 1;
		}

		minute += bt_minute;
		if (minute >= 60) {
			hour++;
			minute -= 60;
		}

		if (flag == 1)
			arvdate++;

		/*결과 출력*/
		cout << "----------------------------" << endl;
		cout << "Departure date : " << date << endl;
		cout << "Departure time : " << dtime << endl;
		cout << "Destination : " << dest << endl;
		cout << "Arrival date : ";
		for (int i = 0; i < 9; i++) {
			cout << date[i];
		}

		cout << "Arrival date: "<<arvdate << endl;

		cout << "Arrival time : ";
		cout.width(2); cout.fill('0');
		cout<< hour << ':' << minute << endl;

	/*output_file.txt 만들기*/
	ofstream out("output_file.txt");

	if (out.is_open()) {
		out << "Departure date : " << date << endl;
		out << "Departure time : " << dtime << endl;
		out << "Destination : " << dest << endl;
		out << "Arrival date : ";
		for (int i = 0; i < 9; i++) {
			out << date[i];
		}

		out << arvdate<< endl;

		out << "Arrival time : ";
		out.width(2); out.fill('0');
		out << hour << ':' << minute << endl;
	}

	out.close();

	system("pause");
	fin.close();
	return 0;

}
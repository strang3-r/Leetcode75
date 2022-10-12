#include <iostream>
using namespace std;
int main() {
  float kelvin;
  int celcuis;
  int c;

  cout << "Please enter if you want to enter the value of temp in 1(for Kelvin "
          "to celsuis) and 2(for celcuis to kelvin)";
  cin >> c;

  switch (c) {
  case 1:
    cout << "Please Enter The Tempratue in Kelvin : ";
    cin >> kelvin;

    cout << "The Tempratue in Celsius is : " << kelvin - 274.15 << 'C' << endl;
    cout << "The approx value in int is : " << int(kelvin - 274.15) << 'C';
    break;

  case 2:
    cout << "Please Enter The Tempratue in Celsius : ";
    cin >> celcuis;

    cout << "The Tempratue in Kelvin is : " << celcuis + 274.15 << 'k' << endl;
    cout << "The approx value in Celcuis is : " << int(celcuis + 274.15) << 'k';
    break;
  default:
    cout << "Please Enter A valid value : ";
    break;
  }
  return 0;
}

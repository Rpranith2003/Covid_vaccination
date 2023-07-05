#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// A struct to represent a beneficiary
struct Beneficiary {
    int id;
    string full_name;
    int year_of_birth;
    string gender;
    int num_of_doses;
};
// A struct to represent a centre
struct Centre {
    int id;
    string name;
    string location;
    string centre_type;
    string vaccine_type;
};
// A struct to represent an appointment
struct Appointment {
    int id;
    int beneficiary_id;
    int centre_id;
    int date;
    int time;
};
// A function to generate a unique beneficiary ID
int generate_beneficiary_id() {
    static int beneficiary_id = 10000;
    return beneficiary_id++;
}
// A function to generate a unique centre ID
int generate_centre_id() {
    static int centre_id = 100;
    return centre_id++;
}
// A function to add a new beneficiary
void add_new_beneficiary(vector<Beneficiary>& beneficiaries) {
    // Get the beneficiary details from the user
    cout << "Enter the beneficiary's full name: ";
    string full_name;
    cin >> full_name;
    cout << "Enter the beneficiary's year of birth: ";
    int year_of_birth;
    cin >> year_of_birth;
    cout << "Enter the beneficiary's gender: ";
    string gender;
    cin >> gender;
    cout << "Enter the number of doses taken(0/1/2): ";
    int num_of_doses;
    cin >> num_of_doses;
    // Create a new beneficiary object
    int generated_ben_id = generate_beneficiary_id();
    Beneficiary beneficiary = {
        generated_ben_id,
        full_name,
        year_of_birth,
        gender,
        num_of_doses
    };
    // Add the beneficiary to the list of beneficiaries
    beneficiaries.push_back(beneficiary);
    cout<<"beneficiary id: "<<generated_ben_id<<" beneficiary name: "<<full_name<<" year of birth: "<<year_of_birth<<" gender:"<<gender<<" number of doses taken:"<<num_of_doses<<endl;
}
// A function to add a new centre
void add_new_centre(vector<Centre>& centres) {
    // Get the centre details from the user
    cout << "Enter the centre's name: ";
    string name;
    cin >> name;
    cout << "Enter the centre's location: ";
    string location;
    cin >> location;
    cout << "Enter the centre's type(government/non-government): ";
    string centre_type;
    cin >> centre_type;
    cout << "Enter the vaccine type(covaxin/covishield/sputnik/zydus/Pfizer/moderna): ";
    string vaccine_type;
    cin >> vaccine_type;
    int generated_cen_id = generate_centre_id();
    // Create a new centre object
    Centre centre = {
        generated_cen_id,
        name,
        location,
        centre_type,
        vaccine_type
    };
    // Add the centre to the list of centres
    centres.push_back(centre);
    cout<<"centre id: "<<generated_cen_id<<" centre name: "<<name<<" location: "<<location<<" centre_type:"<<centre_type<<" vaccine type:"<<vaccine_type<<endl;
}
int generate_appointment_id() {
    int appointment_id_counter = 0;
    return ++appointment_id_counter;
}
// A function to add a new appointment
void add_new_appointment(vector<Appointment>& appointments) {
    // Get the appointment details from the user
    cout << "Enter the beneficiary's ID: ";
    int beneficiary_id;
    cin >> beneficiary_id;
    cout << "Enter the centre's ID: ";
    int centre_id;
    cin >> centre_id;
    cout << "Enter the appointment date: ";
    int date;
    cin >> date;
    cout << "Enter the appointment time: ";
    int time;
    cin >> time;
    // Create a new appointment object
    Appointment appointment = {
        generate_appointment_id(),
        beneficiary_id,
        centre_id,
        date,
        time
    };
    // Add the appointment to the list of appointments
    appointments.push_back(appointment);
}
void cancel_appointment(vector<Appointment>& appointments){
    int ben_id;
    cout<<"Enter the Beneficiary ID: ";
    cin>>ben_id;
    bool flag = false;
    for (Appointment appointment: appointments) 
    {
        if(appointment.beneficiary_id==ben_id){
            flag = true;
            break;
        }
    }
    if (flag) {
        appointments.erase(
        std::remove_if(appointments.begin(), appointments.end(), [&](Appointment const & appointments) {
            return appointments.beneficiary_id == ben_id;
        }),
        appointments.end());
        cout<<"cancelled successfully"<<endl;
    } 
    else {
        cout << "Beneficiary id is not present" << std::endl;
    }
    
}
void remove_beneficiary(vector<Beneficiary>& beneficiaries){
    int ben_id;
    cout<<"Enter the Beneficiary ID: ";
    cin>>ben_id;
    bool flag = false;
    for (Beneficiary beneficiary: beneficiaries) 
    {
        if(beneficiary.id==ben_id){
            flag = true;
            break;
        }
    }
    if (flag) {
        beneficiaries.erase(
            std::remove_if(beneficiaries.begin(), beneficiaries.end(), [&](Beneficiary const & beneficiaries) {
                return beneficiaries.id == ben_id;
            }),
            beneficiaries.end());
        cout<<"deleted successfully"<<endl;
    } 
    else {
        cout << "Beneficiary id is not present" << std::endl;
    }
}
void remove_centre(vector<Centre>& centres){
    int cen_id;
    cout<<"Enter the centre ID: ";
    cin>>cen_id;
    bool flag = false;
    for (Centre centre: centres) 
    {
        if(centre.id==cen_id){
            flag = true;
            break;
        }
    }
    if (flag) {
        centres.erase(
            std::remove_if(centres.begin(), centres.end(), [&](Centre const & centres) {
                return centres.id == cen_id;
            }),
            centres.end());
        cout<<"deleted successfully"<<endl;
    
    } 
    else {
        cout << "Beneficiary id is not present" << std::endl;
    }
    
}
// A function to display the options available to the user
void display_options(vector<Beneficiary>& beneficiaries, vector<Centre>& centres, vector<Appointment>& appointments) {
    // Display the list of beneficiaries
    cout << "List of beneficiaries:" << endl;
    for (Beneficiary beneficiary : beneficiaries) {
        cout << beneficiary.id << ": " << beneficiary.full_name << endl;
    }
    // Display the list of centres
    cout << "List of centres:" << endl;
    for (Centre centre : centres) {
        cout << centre.id << ": " << centre.name << ", " << centre.location <<  endl;
    }
    // Display the list of appointments
    cout << "List of appointments:" << endl;
    for (Appointment appointment : appointments) {
        cout << appointment.id << ": " << appointment.beneficiary_id << ", " << appointment.centre_id << ", " << appointment.date << ", " << appointment.time << endl;
    }
}
void getCentre(vector<Centre>& centres){
    string search_by;
    cout<<"Searching the center by Center ID/name/location/centertype/vaccinetype? Enter anyone of them: ";
    cin>>search_by;
    if(search_by == "ID"){
        int id_centre;
        cout<<"Enter the center ID: ";
        cin>>id_centre;
        bool flag =false;
        for (Centre centre : centres) {
            if(centre.id==id_centre){
                flag=true;
                cout<<"centre name is "<<centre.name << " and it's location is " << centre.location <<  endl;
                break;
            }
        }
        if(!flag){
            cout<<"centre not found"<<endl;
        }
    }
    if(search_by == "name"){
        string name_centre;
        cout<<"Enter the center name: ";
        cin>>name_centre;
        bool flag =false;
        for (Centre centre : centres) {
            if(centre.name==name_centre){
                flag=true;
                cout<<"centre id is "<<centre.id << " and it's location is " << centre.location <<  endl;
            }
        }
        if(!flag){
            cout<<"centre not found"<<endl;
        }
    }
    if(search_by == "location"){
        string location_centre;
        cout<<"Enter the center location: ";
        cin>>location_centre;
        bool flag =false;
        for (Centre centre : centres) {
            if(centre.location==location_centre){
                flag=true;
                cout<<"centre id is "<<centre.id << " and it's name is " << centre.name <<  endl;
            }
        }
        if(!flag){
            cout<<"centre not found"<<endl;
        }
    }
    if(search_by == "centretype"){
        string type_centre;
        cout<<"Enter the center type: ";
        cin>>type_centre;
        bool flag =false;
        for (Centre centre : centres) {
            if(centre.centre_type==type_centre){
                flag=true;
                cout<<"centre id is "<<centre.id << " , it's name is " << centre.name <<" and it's location is " <<centre.location <<  endl;
            }
        }
        if(!flag){
            cout<<"centre not found"<<endl;
        }
    }
    if(search_by == "vaccinetype"){
        string type_vaccine;
        cout<<"Enter the vaccine type: ";
        cin>>type_vaccine;
        bool flag =false;
        for (Centre centre : centres) {
            if(centre.vaccine_type==type_vaccine){
                flag=true;
                cout<<"centre id is "<<centre.id << " , it's name is " << centre.name <<" and it's location is " <<centre.location <<  endl;
            }
        }
        if(!flag){
            cout<<"centre not found"<<endl;
        }
    }
}
int main() {
    // Create a vector of beneficiaries
    vector<Beneficiary> beneficiaries;
    // Create a vector of centres
    vector<Centre> centres;
    // Create a vector of appointments
    vector<Appointment> appointments;
    // Get the user's input
    string command;
    while (true) {
        cout << "Enter a command: ";
        cin >> command;
        // If the user wants to add a new beneficiary
        if (command == "add-beneficiary") {
            add_new_beneficiary(beneficiaries);
        }
        // If the user wants to add a new centre
        else if (command == "add-centre") {
            add_new_centre(centres);
        }
        // If the user wants to add a new appointment
        else if (command == "add-appointment") {
            add_new_appointment(appointments);
        }
        // If the user wants to display the options available
        else if (command == "display-options") {
            display_options(beneficiaries, centres, appointments);
        }
        else if(command == "get-centre"){
            getCentre(centres);
        }
        else if(command == "cancel_appointment"){
            cancel_appointment(appointments);
        }
        else if(command == "remove_beneficiary"){
            remove_beneficiary(beneficiaries);
        }
        else if(command == "remove_centre"){
            remove_centre(centres);
        }
        // If the user wants to exit the program
        else if (command == "exit") {
            break;
        }
    }
    return 0;
}


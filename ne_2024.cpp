#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//patient's structure
struct Patient {
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient *next;
};
Patient *patHead;
//doctor's structure
struct Doctor {
    int doctor_id;
    string name;
    string specialization;
    Doctor *next;
};
Doctor *docHead;
//appointment structure
struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment *next;
};
Appointment *appointHead;
//lists
list<Patient> patientsLL;
list<Doctor> doctorsLL;
list<Appointment> appointments;

//function to register a new patient
void registerPatient() {
    cout<<"     REGISTERING A NEW PATIENT   "<<endl;
    cout<<"----------------------------------"<<endl;
    Patient newPatient;
    cout << "Enter patient ID: ";
    cin >> newPatient.patient_id;
    //checks if the patient doesnt already exists
    for (auto it = patientsLL.begin(); it != patientsLL.end(); it++) {
        if (it->patient_id == newPatient.patient_id) {
            cout << "ALERT: Patient with this ID already exists, consider another ID." << endl;
            return;
        }
    }
    cout << "Enter patient name: ";
    cin >> newPatient.name;
    cout << "Enter patient DOB: ";
    cin >> newPatient.dob;
    cout << "Enter patient gender(female or male): ";
    cin >> newPatient.gender;
    if(newPatient.gender =="female" || newPatient.gender =="male"){
        patientsLL.push_back(newPatient);
    }
    else{
        cout <<"ALERT: gender should be female or male..."<<endl;
        return;
    }
    //save to patients.csv file
    ofstream file("patients.csv", ios::app);
    if (file.is_open()) {
        file << newPatient.patient_id << ", " << newPatient.name<<", "<<newPatient.dob<<", "<<newPatient.gender;
        file << endl;
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    cout<<"    patient saved succesfully..."<<endl;
}

//register a new doctor
void registerDoctor() {
    cout<<"    REGISTERING A NEW DOCTOR   "<<endl;
    cout<<"-------------------------------"<<endl;
    Doctor newDoctor;
    cout << "Enter doctor ID: ";
    cin >> newDoctor.doctor_id;
    //checks availability of the doctor
    for (auto it = doctorsLL.begin(); it != doctorsLL.end(); it++) {
        if (it->doctor_id == newDoctor.doctor_id) {
            cout << "ALERT: Doctor with this ID already exists, consider another ID." << endl;
            return;
        }
    }
    cout << "Enter doctor name: ";
    cin >> newDoctor.name;
    cout << "Enter doctor specialization: ";
    cin >> newDoctor.specialization;
    doctorsLL.push_back(newDoctor);
    //save to a doctors.csv file
    ofstream file("doctors.csv", ios::app);
    if (file.is_open()) {
        file << newDoctor.doctor_id << ", " << newDoctor.name<<", "<<newDoctor.specialization;
        file << endl;
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    cout<<"   doctor saved succesfully..."<<endl;
}
//register a new appointment
void registerAppointment() {
    cout<<"     REGISTERING AN APPOINTMENT   "<<endl;
    cout<<"----------------------------------"<<endl;
    Appointment newAppointment;
    cout << "Enter appointment ID: ";
    cin >> newAppointment.appointment_id;
    //checks the id of the appointment
    for (auto it = appointments.begin(); it != appointments.end(); it++) {
        if (it->appointment_id == newAppointment.appointment_id) {
            cout << "ALERT: Appointment with this ID already exists, consider another ID." << endl;
            return;
        }
    }
    //checks if the patient's id exists
    cout << "Enter patient ID: ";
    cin >> newAppointment.patient_id;
    for (auto it = patientsLL.begin(); it != patientsLL.end(); it++) {
        if (it->patient_id == newAppointment.patient_id) {
            break;
        } else {
            cout << "Patient with this ID does not exist." << endl;
            return;
        }
    }
    //checks if the doctor's ID exists
    cout << "Enter doctor ID: ";
    cin >> newAppointment.doctor_id;
    for (auto it = doctorsLL.begin(); it != doctorsLL.end(); it++) {
        if (it->doctor_id == newAppointment.doctor_id) {
            break;
        } else {
            cout << "Doctor with this ID does not exist." << endl;
            return;
        }
    }
    cout << "Enter appointment date: ";
    cin >> newAppointment.appointment_date;
    appointments.push_back(newAppointment);
    ofstream file("appointments.csv", ios::app);
    if (file.is_open()) {
        file << newAppointment.appointment_id << ", " << newAppointment.patient_id<<", "<<newAppointment.doctor_id<<", "<<newAppointment.appointment_date;
        file << endl;
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    cout<<"   appointment saved successfully...";
}
//displaying available patients
void displayPatients() {
    cout<<"   DISPLAYING AVAILABLE PATIENTS   "<<endl;
    cout<<"-----------------------------------"<<endl;
    for (auto it = patientsLL.begin(); it != patientsLL.end(); it++) {
        cout << "Patient ID: " << it->patient_id << ", Name: " << it->name << ", DOB: " << it->dob << ", Gender: " << it->gender << endl;
    }
}
//displaying available doctors
void displayDoctors() {
    cout<<"    DISPLAYING AVAILABLE DOCTORS    "<<endl;
    cout<<"-------------------------------------"<<endl;
    for (auto it = doctorsLL.begin(); it != doctorsLL.end(); it++) {
        cout << "Doctor ID: " << it->doctor_id << ", Name: " << it->name << ", Specialization: " << it->specialization << endl;
    }
}
//displaying doctor's appointments
void displayAppointments() {
    cout<<"   DISPLAYING AVAILABLE APPOINTMENTS   "<<endl;
    cout<<"---------------------------------------"<<endl;
    for (auto it = appointments.begin(); it != appointments.end(); it++) {
        cout << "Appointment ID: " << it->appointment_id << ", Patient ID: " << it->patient_id << ", Doctor ID: " << it->doctor_id << ", Date: " << it->appointment_date << endl;
    }
}
//the main function
int main() {
    int choice;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"    ----------Welcome to Ruhengeri Referral Hospital---------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    while (true) {
        //the menu
        cout<<"Menu: "<<endl;
        cout << "1. Register a patient" << endl;
        cout << "2. Register a doctor" << endl;
        cout << "3. Register an appointment" << endl;
        cout << "4. Display patients" << endl;
        cout << "5. Display doctors" << endl;
        cout << "6. Display appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice please: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                registerAppointment();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                displayDoctors();
                break;
            case 6:
                displayAppointments();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid option. Please choose again." << endl;
        }
    }
    return 0;
}









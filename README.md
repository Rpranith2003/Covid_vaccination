# Covid vaccination

This was a user-friendly C++ program that was developed to create a covid vaccination platform. It allowed users to effectively manage beneficiaries, vaccination centres, and appointments for vaccine administration.

## Features

- Add New Beneficiaries: Users had the capability to add new beneficiaries to the system. They could provide relevant details such as the beneficiary's full name, year of birth, gender, and the number of vaccine doses they have taken.
- Add New Centres: Users could easily add new vaccination centres to the system. They simply needed to input the centre's name, location, type (government/non-government), and the specific vaccine being administered.
- Schedule Appointments: The program allowed users to conveniently schedule appointments for beneficiaries at their preferred vaccination centres. They could specify the date and time for the appointment.
- Cancel Appointments: Users had the option to cancel appointments for beneficiaries if needed.
- Remove Beneficiaries: The program enabled users to remove beneficiaries from the system if required.
- Remove Centres: Users also had the flexibility to remove vaccination centres from the system when necessary.
- Display Options: Users could easily view the list of beneficiaries, vaccination centres, and appointments available within the system.
- Get Centre Details: The program offered a search functionality that allowed users to find specific vaccination centres by their ID, name, location, centre type, or vaccine type.

## Functionalities:

1. *Structs*: The program defined three structs: `Beneficiary`, `Centre`, and `Appointment`. These structs stored the relevant information for beneficiaries, vaccination centres, and appointments, respectively.
2. *ID Generation*: The code included functions to generate unique IDs for beneficiaries and vaccination centres. These IDs were automatically incremented each time a new beneficiary or centre was added to the system.
3. *Adding Beneficiaries*: The `add_new_beneficiary` function facilitated the addition of new beneficiaries to the system. Users were prompted to enter details such as the beneficiary's full name, year of birth, gender, and the number of vaccine doses taken.
4. *Adding Centres*: The `add_new_centre` function streamlined the process of adding new vaccination centres to the system. Users were prompted to input details such as the centre's name, location, type (government/non-government), and the type of vaccine being administered.
5. *Adding Appointments*: The `add_new_appointment` function allowed users to conveniently schedule appointments for beneficiaries. They could specify the beneficiary ID, centre ID, appointment date, and time.
6. *Cancelling Appointments*: Users had the ability to cancel appointments for beneficiaries through the `cancel_appointment` function. They simply needed to provide the beneficiary ID, and the corresponding appointment would be removed from the system.
7. *Removing Beneficiaries and Centres*: The program provided functions, namely `remove_beneficiary` and `remove_centre`, to remove beneficiaries and vaccination centres from the system. Users were required to provide the ID of the beneficiary or centre they wished to remove.
8. *Displaying Options*: The `display_options` function conveniently displays the list of beneficiaries, vaccination centres, and appointments currently stored in the system.
9. *Searching for Centres*: The `getCentre` function allows users to search for specific vaccination centres based on various criteria, including ID, name, location, centre type, or vaccine type. Users were prompted to specify their desired search criteria, and the relevant centre information was displayed.
10. *Main Program*: The main program ensured a smooth user experience by continuously prompting the user for commands and calling the corresponding functions based on the input. It supported commands such as adding beneficiaries, vaccination centres, and appointments, cancelling appointments, removing beneficiaries and centres, displaying options, and exiting the program.

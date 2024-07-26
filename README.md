# AsignaTurns
## Description
AsignaTurns is a project developed for the course Laboratory of Computing II at university. The purpose of this application is to manage appointments for a clinic or medical office, providing functionalities for both administrative staff and doctors.

## Development Team
- **Franco Liutkevier**
- **Vitelli Ignacio**
- **Vercellini Belén**

## Features

### Main Screen
The application is intuitive from the start, with a selection screen, where the user can choose between two options:

1. **Administration**
2. **Doctor**

### Administration Section
In the administration section, the following options are available:

- **Patient Management:** Allows for creating, modifying, listing, and deleting patients.
  - **Create** (In case of charge the same DNI)
    ![1_CargaPat](https://github.com/user-attachments/assets/deff1ce0-3b2c-4bfb-92aa-22998b4478b8)
    ![6_CasoDeCargarElMismoDNI](https://github.com/user-attachments/assets/13633b5c-196e-4344-8f63-d86a242a81ed)

  - **List** (Using 'DNI' as filter too)
    ![3_ListarTodosLosPacientes](https://github.com/user-attachments/assets/450aa811-00e5-4b9a-bc24-fe8f9a6a9649)
    ![2_BusquedaPorDni](https://github.com/user-attachments/assets/45745c5a-f119-45ba-893f-49cf3001d4c5)
    
  - **Modify**
    ![4_ModificarPat](https://github.com/user-attachments/assets/31b0b971-eaba-4916-94fc-a965721cb93d)
    
  - **Delete**
    ![5_darDeBaja](https://github.com/user-attachments/assets/1f38969c-d6d6-40b3-b77c-1f0a82c03658)
    


- **Doctor Management:** Similar to patients, allows for full management of doctors.
  - **Create** (In this case, I loaded two doctors to serve as examples for later appointments)
    ![1_FirstDoctor](https://github.com/user-attachments/assets/4e82744f-b9f8-4af0-a546-50e93500236e)
    ![2_SecondDoctor](https://github.com/user-attachments/assets/f83ec7e6-bb8a-4f35-b95c-febebb00776d)


  - **List** (Using 'Legajo' and 'Especialidad' as filters too.)
    ![3_buscarxLegajoEspecialidadyListar](https://github.com/user-attachments/assets/5546212c-d98c-490a-bc8c-438a7dc5eef6)

    
  - **Modify**
    ![4_MenuModificarD](https://github.com/user-attachments/assets/be60849e-cd6c-4e02-9a76-d9bf27474d33)

- **Appointment Management:**
  - Create, modify, list, and delete appointments.
  - When creating an appointment, a doctor, patient, and schedule are selected. Only available appointments can be seen, which must have been previously configured. The doctor must be available and have the specialty required by the patient.
  - **Create** (Creating an available appointment, then i can give that appointment to a patient)
    ![1_AgregarTurnoDisponible](https://github.com/user-attachments/assets/9c171eff-f1e1-4bf7-88ae-98064812e7d8)

  - **List** (First, I create another appointment marked as 'Disponible', where you can see all appointments.)
    ![2_AgregarOtroDisponibleYListarDispo](https://github.com/user-attachments/assets/b28e4665-8f43-4fa3-a2bc-efbad7afab5d)


  - **Create the appointment** (It has an Id and is only for one patient)
    ![3_AgregarTurnoAPaciente_ListarTurnosDispo_ListarT](https://github.com/user-attachments/assets/e6bffe3f-2d89-40ee-a024-a5cde1902759)

- **Options Management:**
  - Create database backups.
  - Restore data from a backup.
  - Restore data that has been logically deleted.
  - Permanently delete data that has been logically deleted.

### Doctor Section
Doctors can access their section using a valid ID number. The available options for doctors include:

- List appointments assigned to the doctor.
- List appointments by date for the doctor.
## Technologies Used
- **Programming Language:** C++
- **Application Type:** Console.
- **Data Management:** .dat and .bkp files.

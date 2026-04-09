# Further technical test

---

## Content of the repository

The respository contains under `data/` the file `dimuon_91.txt` with the particles generted by Pythia8 in the simulation of 10000 e+e- -> mu+mu- events at sqrt(s) = 91.2 GeV.
The format is ASCII. Each line starts either by letter 'E' or letter 'P'.
The letter 'E' indicates the beginning of an event and it is followed by the event number and
some other information on the event.
The letter 'P' indicates a particle; it is followed by some information which includes the particle type (as per PDG), third integer after initial letter, the momentum along the three axis (x,y,z),
the energy, the mass, and the status. Status 1 means stable.

---

## Task 1
Under `f77/` you can find the program `convertMC.F`, which is a fortran77 program reading the file `data/dimuon_91.txt`, printing each line and counting the number of events.
You can compile it in thsi way:
```
$ gfortran -o f77/convertMC f77/convertMC.F
```
and run it
```
$ ./f77/convertMC
...
 DONE!        10000
```

The task consist in modifying the code to write into a separate file under `data` the event number and the relevant information for the stable particles only.
The output file should be identical to the reference file `data/dimuon_91_stable.txt`. Note that the lines have not the same format.

## Task 2
Under `cpp/`, `Event.h` defines a simplified Event class which you van load in `ROOT`:
```
$ root -l
root [0] .L cpp/Event.h++
Info in <TUnixSystem::ACLiC>: creating shared library /home/ganis/aleph/GIT/TechTest/./cpp/Event_h.so
root [1] .q
```
The task consists in writing a ROOT macro that reads the output of the previous program, i.e. `data/dimuon_91_stable.txt ` and creates a `ROOT TTree` of `Event` entries and saves it to a file.

## Task 3
This task consist in writing a script or macro to visualise the sum of the muon energies. You can use whatever tool you want. Put the macro in the top directory.

---
## Notes
1. You can use whatever tools you prefer to find a solution. During the discussion you have to be ready to demonstrate to understand what you have provide,
possibly being ready to implement some modifications
2. Fork the repository in your own area and provide access to your own version of the repository for us to examine and run your solutions

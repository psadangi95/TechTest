      PROGRAM convertMC
      IMPLICIT NONE
!     Fortran77 program to read MC data from a text file and coverting to a
!     different format for further processing
      INTEGER UIN, UOUT
      INTEGER NEV, NP, IEV, NIdx, NPDG, NSTATUS
      DOUBLE PRECISION Px, Py, Pz, EN, M
      
      CHARACTER*80 FINNAM_IN
      CHARACTER*80 FINNAM_OUT
      CHARACTER*200 LINE

!     Open input file
      UIN = 10
      UOUT = 20
      FINNAM_IN = 'data/dimuon_91.txt'
      OPEN(UIN, FILE = FINNAM_IN, STATUS = 'OLD')

      FINNAM_OUT = 'data/dimuon_91_update.txt'
      OPEN(UOUT, FILE = FINNAM_OUT, STATUS = 'UNKNOWN')

!     Loop
      NEV=0 
!      NLINE = 0
      DO WHILE (.TRUE.)
         READ(UIN,'(A)',END=100) LINE
         IF (LINE(1:1) .EQ.'E') THEN
            READ(LINE,*) LINE(1:1), IEV, NIdx, NPDG
            WRITE(UOUT,*) LINE(1:1), ':', NEV
            NEV = NEV + 1
         ELSE IF (LINE(1:1) .EQ.'P') THEN
               READ(LINE,*) LINE(1:1), NP, NIdx, NPDG, Px, Py, Pz, EN, M, NSTATUS
               IF (NSTATUS .EQ. 1) THEN
                  WRITE(UOUT,*) LINE(1:1), ':', NP, NPDG, Px, Py, Pz, EN, M
               ENDIF
         ENDIF
!         WRITE(*,*) NLINE, LINE
      END DO
      
 100  WRITE(*,*) 'DONE! ', NEV
      CLOSE(UIN)
      CLOSE(UOUT)

      END
      


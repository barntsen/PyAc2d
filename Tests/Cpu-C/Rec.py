"""
Receiver object

This script defines a class for creating a receiver object that allows to records seismograms, the presure wavefield
and saves the results as bin files.

@author: Stefan Catalin Craciun
"""

import numpy as np
import matplotlib.pyplot as plt


class Rec:
    def __init__(self, rx, ry, nt, resamp, sresamp, nx, ny, dx, Nb, dt, gx=0, gy=0):
        """
        Initializes a new receiver object with the given receiver locations and parameters.
        
        Parameters
        ----------
        rx : integer array
             X coordinates (gridpoints) of the receiver locations.
        ry : integer array
             Y coordinates (gridpoints) of the receiver locations.
        nt : int
             Number of time samples in the receiver data.
        resamp : int
             Resampling rate for pressure recording (seismogram).
        sresamp : int
             Resampling rate for wavefield animation.
        nx : int
             Number of grid points along the X axis.
        ny : int
             Number of grid points along the Y axis.
        dx : float
             Grid spacing interval in both x and y directions.
        Nb : int
             The number of boundary grid points.
        dt : float
             Time step increment for the simulation.
        gx : int, optional
             X coordinate for just 1 receiver (1 trace), default is 0.
        gy : int, optional
             Y coordinate for just 1 receiver (1 trace), default is 0.
        """
        self.nr = len(rx)       # No of receivers
        self.rx = rx
        self.ry = ry
        self.nt = nt
        self.p = np.zeros((self.nr, self.nt), dtype=float)  # Pressure p[i,j] time sample
                                                            # at position i, j 
        self.resamp = resamp
        self.sresamp = sresamp
        self.pit = 0
        self.counter = 0
        self.gx = gx
        self.gy = gy
        self.nx = nx
        self.ny = ny
        self.dx = dx
        self.Nb = Nb
        self.dt = dt
        self.wavefield = np.zeros((self.nx, self.ny, int(nt/sresamp)+1))
        

    def rec_trace(self, it, p):
        """
        
        Not working
        
        
        Records the pressure values at just 1 receiver location.
        
        Parameters
        ----------
        it : int
            Current time step.
        p : numpy array
            Pressure values at the current time step.
        
        Returns
        -------
        str
            "ERR" if the current time step exceeds the total number of time steps or "OK" otherwise.
        """
        if self.pit > self.nt - 1:
            return "ERR"

        if it % self.resamp == 0:
            for pos in range(self.nr):
                ixr = int(self.rx[pos])
                iyr = int(self.ry[pos])
                self.p[pos, self.pit] = p[ixr, iyr]
            self.pit += 1
        #print(self.p.shape)
        return "OK"
    
    
    def rec_seismogram(self, it, snp):
        """
        Records the pressure values at the specified receiver locations (seismogram).
        
        Parameters
        ----------
        it : int
            Current time step.
        snp : numpy array
            Pressure values at the current time step.

        Returns
        -------
        str
            "ERR" if the current time step exceeds the total number of time steps or "OK" otherwise.
        """
        if self.pit > self.nt - 1:
            return "ERR"

        if it % self.resamp == 0:
            for pos in range(self.nr):
                ixr = int(self.rx[pos])
                iyr = int(self.ry[pos])
                self.p[pos, self.pit] = snp[iyr, ixr]
            self.pit += 1
       
        return "OK"
    
    def rec_wavefield(self, it, snp):
        """
        Stores wavefield snapshots at a given time step if the time step is a multiple of the snapshot resampling rate.
        Records the wavefield.
        
        Parameters
        ----------
        it : int
            Current time step.
        snp : numpy array
            Pressure values at the current time step for wavefield snapshots
            
        Returns
        -------
        str
            "OK" after storing the wavefield snapshot.
        """
        if self.sresamp <= 0:
            return "OK"

        if it % self.sresamp == 0:
            self.wavefield[:,:,self.counter] = snp
            #plt.imshow(self.wavefield[:,:,self.counter], cmap='bwr', vmin=-5e-10, vmax=5e-10)
            #plt.imshow(self.wavefield[:,:,self.counter], cmap='bwr', vmin=-1e-15, vmax=1e-15)
            #plt.show()
            #print(self.counter)
            self.counter += 1

        return "OK"


    
    def seismogram_save(self):
        """
        Saves the seismogram data to a binary file called seismogram.bin
        in the Visualization folder.
        
        Returns
        -------
        str
            "OK" after successfully saving the seismogram data.
        """
        output_file = "Visualization/seismogram.bin"
        print(self.p.shape)
        plt.imshow(self.p)
        # Save the shape of the seismogram as metadata  nt, nr, dt, dx, Nb
        metadata = np.array(self.p.shape, dtype=int)
        metadata = np.append(metadata, self.dt)
        metadata = np.append(metadata, self.dx)
        metadata = np.append(metadata, self.Nb)
        
        print(metadata)
        
        with open(output_file, "wb") as f:
            metadata.tofile(f)
            # Save the wavefield data
            self.p.tofile(f)
            
            print(f"Seismogram data saved to {output_file}")
        return "OK"
   
    def wavefield_save(self):
        """
        Saves the wavefield data to a binary file called wavefield.bin
        in the Visualization folder.
        
        Returns
        -------
        str
            "OK" after successfully saving the wavefield data.
        """
        output_file = "Visualization/wavefield.bin"
        
        # Save the shape of the wavefield as metadata
        metadata = np.array(self.wavefield.shape, dtype=int)
        metadata = np.append(metadata, self.dx)
        metadata = np.append(metadata, self.Nb)
        
        print(metadata)
   
        with open(output_file, "wb") as f:
            metadata.tofile(f)
            # Save the wavefield data
            self.wavefield.tofile(f)
        
        print(f"Wavefield data saved to {output_file}")
        return "OK"








        
        
        
        
        
        
  
        """
        
        #-----------------------------------------------
        #-----------------------------------------------
        #-----------------------------------------------
        # Seismogram
        #-----------Receiver Line Coordinates------------------------------------
        Linez = 100 #m  Depth of Receiver Line
        izline = int(Linez/dz)

        seis = np.zeros([nt,nx])
        for i in range(0,int(nt)):
            seis[i,:]=p[izline,:,i]

        labelsize = 16
        pl.figure(facecolor='white')
        pl.title('Seismogram, Time = {}s'.format(round(i*dt,2)), fontsize=labelsize)
        pl.imshow(seis, cmap='bwr', vmin=-pmax,vmax=pmax, extent=[ax[0],ax[-1],int(Time*1000),0], aspect='equal')
        pl.xlabel('Distance (m)', fontsize=labelsize)
        pl.ylabel('Time (m)', fontsize=labelsize)
        pl.xlim(0,Length)
        pl.xticks(fontsize=labelsize)
        pl.yticks(fontsize=labelsize)
        pl.colorbar(label = 'Pressure')
        pl.savefig("Seismogram.svg", format="svg", bbox_inches = 'tight')
        pl.show()
        
        #print(Rec.p)
        #img_seismogram =  plt.imshow(Rec.p)
        #plt.savefig(args, kwargs)
        """
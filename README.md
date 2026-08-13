# MiniPET Project

### A conceptual simulation of PET detection, coincidence timing and Time-of-Flight

This is a self-directed project where I explore the fundamentals of Positron Emission Tomography (PET) from a physics and engineering perspective.

I wanted to understand what happens between a physical event and the moment when a detector system turns it into useful data. For this, I developed a simplified MiniPET model combining detector geometry, gamma-ray emission, simulated detector signals, coincidence detection, timing analysis and basic optimization.

The project is mainly focused on learning and experimentation rather than reproducing a real clinical PET scanner.

## What am I exploring?

The simplified detection chain is represented as:

**Positron annihilation → Two 511 keV photons → Detector ring → Scintillator + MPPC concept → Electrical signal → Timing extraction → Coincidence detection → Line of Response (LOR) → Time-of-Flight / spatial information**

Some of the main concepts explored in the project are:

- PET detector geometry
- Positron-electron annihilation
- 511 keV gamma photons
- Scintillation detector concepts
- MPPC / SiPM signal modeling
- Electronic noise and timing uncertainty
- Coincidence windows
- Data acquisition (DAQ)
- Time-of-Flight (TOF)
- Detection efficiency
- Scientific visualization

## Python and C++

I wanted to explore how the same detector system can be approached at different levels.

Python is mainly used for simulation, visualization, statistical analysis, parameter sweeps and optimization.

C++ is used to model a simplified DAQ coincidence logic, with a focus on event processing, detection timestamps and coincidence decisions.

The general workflow is:

**Python → Simulation → visualization → analysis → optimization → C++ → Event processing → coincidence logic → DAQ model**

This was also a way for me to connect high-level scientific analysis with lower-level hardware-oriented thinking.

## Coincidence Window

One of the main questions I wanted to explore was:

> How does the coincidence window affect detection efficiency and timing uncertainty?

Two detections are considered coincident when:

$$
|t_1-t_2| < \Delta t_c
$$

where $\Delta t_c$ is the coincidence window.

I tested several window sizes and analyzed how increasing the window affects the number of accepted events.

Using the assumptions of this simplified model, the analysis produced an optimal region around:

$$
\Delta t_c \approx 1.0-1.5\,ns
$$

This should not be interpreted as a universal optimum for real PET systems. It is the result obtained from the assumptions and parameters used in this particular simulation.

## Time-of-Flight

I also explored how timing information can be related to spatial localization along the Line of Response.

The simplified relation used in the project is:

$$
\Delta x = \frac{c\Delta t}{2}
$$

This was especially interesting to me because it connects detector and electronics-level information, such as timing, with a higher-level imaging property: spatial localization.

## Visualization

I don't see visualization only as a way of presenting the final results.

During the project, plots became part of the analysis itself. They helped me:

- check whether the detector geometry was behaving correctly
- understand simulated annihilation events
- inspect signal noise and timing
- identify saturation regions
- compare Python and C++ results
- understand the trade-offs involved in optimization

This is connected to my broader interest in combining physics, engineering, computation and visual approaches when working with complex scientific systems.

## Current limitations

This is still a conceptual model, so it does not currently include:

- full GEANT4 particle transport
- detailed radiation-matter interactions
- Compton scattering
- photoelectric interactions
- realistic scintillator light transport
- detailed MPPC/SiPM physics
- realistic electronics transfer functions
- detector dead time and pile-up
- 3D PET geometry
- experimental detector data
- complete tomographic image reconstruction

These limitations are intentional starting points and also define some of the possible directions for future development.

## Possible next steps

Some of the directions I would like to explore are:

- [ ] Implement a more detailed detector model using GEANT4
- [ ] Introduce more realistic radiation-matter interactions
- [ ] Explore scintillator and SiPM/MPPC response
- [ ] Include experimental detector data
- [ ] Investigate FPGA-oriented coincidence processing
- [ ] Improve the TOF model
- [ ] Extend the detector geometry to 3D
- [ ] Explore image reconstruction
- [ ] Connect simulation with real instrumentation

## Tools

- Python
- C++
- NumPy
- Matplotlib
- ROOT
- GEANT4 (introductory / future development)
- Linux
- Git
- LaTeX / Overleaf

## Why am I doing this?

I'm currently studying Automation and Robotics Engineering, after previously studying Physics Engineering, and I became interested in the space between both areas.

I'm especially interested in detector instrumentation, medical physics, electronics, data acquisition and experimental systems. I wanted to build something where I could learn about these areas by actually putting them together instead of studying them separately.

This project is still evolving, but my goal is to progressively move from a conceptual simulation toward more realistic detector modeling and eventually experimental systems.

> From physical events → signals → data → information.


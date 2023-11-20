<h1 align="center">Fractals generator</h1>

<p align="center">
  <a href="#overview">Overview</a> •
  <a href="#features">Features</a> •
  <a href="#screenshots">Screenshots</a> •
  <a href="#system-design">System Design</a> •
  <a href="#license">License</a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/License-MIT-yellow.svg" />
  <img src="https://img.shields.io/badge/Author-SmartMatt-blue" />
</p>

## Overview
This repository hosts a client application for generating fractals, specifically Julia and Mandelbrot sets. The application leverages multi-threading for enhanced performance, allowing users to generate fractal images swiftly. It offers the flexibility to choose between C++ and Assembly (ASM) for the core algorithm, enabling further optimization based on user preference.

## Features
- **Fractal Types**: Generate two types of fractals - Julia and Mandelbrot.
- **Customizable Parameters**: Control over image size, scale, fractal type, and offset.
- **Multi-threading Support**: Speed up image generation through efficient multi-threading.
- **Algorithm Choice**: Option to select between C++ or ASM for the fractal generation algorithm.
- **Performance Optimization**: User-configurable thread count and algorithm selection for optimal performance.
- **Execution Time Tracking**: The system returns the duration of the generation process.
- **Image Saving**: Save fractals in .bmp format.
- **Accessibility**: User-friendly control via a GUI panel

# Screenshots
![Presentation of application](https://smartmatt.pl/github/fractals-generator/fractals-generator-1.png)
*Presentation of the application panel and the fractal it generated.*

![Mandelbrot fractal](https://smartmatt.pl/github/fractals-generator/fractals-generator-2.png)
*Generated mandelbrot fractal.*

![Julia fractal](https://smartmatt.pl/github/fractals-generator/fractals-generator-3.png)

*Generated Julia fractal.*

## System Design
- Built on a CLR + C++ project framework.
- Incorporates an additional execution algorithm in ASM.
  
### Repository Contents
- Complete project with all dependencies.
- Pre-built version of the application for immediate use.

### Codebase
- **Syntax**: English.
- **Comments**: Polish.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
&copy; 2023 Mateusz Płonka (SmartMatt). All rights reserved.
<a href="https://smartmatt.pl/">
    <img src="https://smartmatt.pl/github/smartmatt-logo.png" title="SmartMatt Logo" align="right" width="60" />
</a>

<p align="left">
  <a href="https://smartmatt.pl/">Portfolio</a> •
  <a href="https://github.com/SmartMaatt">GitHub</a> •
  <a href="https://www.linkedin.com/in/mateusz-p%C5%82onka-328a48214/">LinkedIn</a> •
  <a href="https://www.youtube.com/user/SmartHDesigner">YouTube</a> •
  <a href="https://www.tiktok.com/@smartmaatt">TikTok</a>
</p>

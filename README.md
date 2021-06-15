# Xita Cross-Compiler (AArch64)
#### Version: v0.24
**NOTE:  For sake of consistency, this repository will be renamed to `Xita-AArch64` starting with v0.25.**

This respository provides the Linux-to-Xita cross compiler.  This **X-Ita Control System** compiler targets ARM's AArch64 architecture.  As of the current version, it specifically targets BCM 2837 (Rasberry Pi 3 B+).  However, it could be adapted to fit other AArch64 chips with ease.  

### Table of Contents

* [Prerequisites](#prerequisite-installation)
  * [Arch/Antergos](#arch/antergos)
  * [Red Hat-Like](#centos/rhel/scientific-linux/fedora)
  * [Fedora 22+](#fedora-22+)
  * [Debian-Like](#debian/ubuntu/mint)
* [Installation](#XCSL-AArch64-Cross-Compiler-Installation)
  * [Clone Repository](#clone-the-repository)
  * [Install XCSL-AArch64](#build-and-install-xcsl)
  * [Build XCSL-AArch64](#build-xcsl-and-do-not-install)
  * [Uninstall XCSL-AArch64](#uninstall-xcsl)
* [Usage](#xcsl-terminal-usage)
  * [Live Interpreter](#live-interpreter)
  * [Cross-Compiler](#xcs-cross-compiler)
  * [Terminal Options](#terminal-options)



### Clone the Repository

```bash
$  mkdir CodeusTech && cd CodeusTech
$  git clone https://github.com/CodeusTech/XCSL-AArch64.git
```
**NOTE:** Two-Factor Authentication *must* be enabled.

### Prerequisite Installation 

##### Arch/Antergos

``` bash
$  sudo pacman -Syyu
$  sudo pacman -S make gcc flex bison
```

##### CentOS/RHEL/Scientific Linux/Fedora

``` bash
$  sudo yum update
$  sudo yum group install "Development Tools"
```

##### Fedora 22+

``` bash
$  sudo dnf upgrade --refresh
$  sudo dnf groupinstall "Development Tools"
$  sudo dnf groupinstall "C Development Tools and Libraries"
```

##### Debian/Ubuntu/Mint

``` bash
$  sudo apt-get update
$  sudo apt-get upgrade
$  sudo apt-get install build-essential flex flexc++ bison bisonc++
```

#####  Cross-Assembler

To use the Xita Cross-Compiler, we need a compliant AArch64 cross-compiler.  Using the command below will uncompress the cross-assembler into the correct location for Xita internal use.  

**NOTE: Xita expects the cross assembler to reside in ~/.opt/cross**.

```bash
$  cd XCSL-AArch64/
$  tar xf aarch64-assembler.tar.xz -C $HOME
```

### Xita-AArch64 Cross-Compiler Installation

##### Build and Install Xita

```bash
$  make install
```

##### Build Xita and Do NOT Install

```bash
$  make build
```

##### Uninstall Xita

```bash
$  make uninstall
```

###  Xita Terminal Usage 

The following usage commands assume XCS-AArch64 is installed on the current
Linux system.  If it is only built (and not installed), you will need to
use:   ` $  _build/xcs-aarch64 [...] `


```bash
$  xcs-aarch64 [OPTIONS] [file1 file2 ...]
```

##### Terminal Options

Command-line options can be fed to either the live interpreter or cross-compiler.  
See the following list for option syntax and functionality.

*  --version
*  -v  |  --verbose  


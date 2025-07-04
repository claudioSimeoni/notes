# 1️⃣ Fundamentals 

## 📌HARDWARE

#### CPU

The **CPU** (Central Processing Unit) is essentially the core of the computer; it handles all the computations required by programs. It performs these tasks using **transistors**, tiny electronic switches that operate on the scale of nanometers. When current flows, it represents a 1 bit; when it doesn’t, it represents a 0 bit. These are the main components of the CPU:

- **Cores**: These are individual processing units within the CPU, capable of working independently. Having multiple cores allows the CPU to handle multiple tasks simultaneously, improving performance in multi-threaded programs.
- **ALU** (Arithmetic Logic Unit): This part of the CPU performs arithmetic and logical operations, such as addition, subtraction, and comparison.
- **FPU** (Floating Point Unit): This is a specialized unit within the CPU that handles calculations with floating-point numbers, which require more complex computations than simple integers.
- **Control Unit**: This unit is responsible for directing the operation of the CPU. It fetches, decodes, and executes instructions.
- **Registers**: Small, fast storage locations within the CPU used to hold temporary data, such as variables and intermediate results, during the execution of instructions.
- **Cache**: A small but very fast memory located close to the CPU, used to store frequently accessed data. There are typically three levels: **L1**, **L2**, and **L3**, with **L1** being the smallest and fastest, and **L3** being larger but slower.
- **Bus Interface Unit**: This unit manages data exchanges between the CPU and the memory (RAM).

The **clock** of the CPU dictates how frequently it executes instructions. Overclocking the CPU means increasing this clock frequency, which can result in faster performance but also generates more heat and consumes more power. The **ISA** (Instruction Set Architecture) defines the set of instructions the CPU can execute. 

>x86 and arm are types of CPU architecture

---
#### RAM

**RAM** (Random Access Memory) is a **temporary** and **volatile** memory that stores data used by running programs. It’s volatile because all data is lost when the computer is turned off. RAM is **very fast** because it’s designed to store data that changes frequently while programs are running.

RAM is divided into **cells**, each of which stores a single bit. Each cell contains a **transistor** for reading the data and a **capacitor** for storing the data. Since capacitors lose their charge over time, they must be periodically refreshed, which results in high **power consumption**.

RAM interacts constantly with the CPU. When the CPU needs data, it first checks the cache, and if it’s not there, it requests the data from RAM.

---
#### STORAGE

**HDD** (Hard Disk Drive) is a mass storage device commonly used in desktops and servers. It uses **magnetic rotating disks** to store data. A specific region of the disk is magnetized to store a bit. **Reading** and **writing** data are done using a **metallic arm** with a **magnetic head** that moves over the rotating disk. These mechanical operations make HDDs slower compared to newer storage technologies. As a result, algorithms that require frequent access to data stored on HDDs need to be optimized to minimize disk access.

**SSD** (Solid State Drive) is a newer storage technology used in laptops and desktops. It stores data using **floating gates** (specialized transistors that trap electrons) instead of magnetic disks. Writing data involves injecting charge into these floating gates, while reading data is done by measuring the voltage in the gate. SSDs are faster and more durable than HDDs because they have no mechanical parts.

---
#### GPU

The **GPU** (Graphics Processing Unit) is designed to handle the computation-heavy tasks related to graphics, such as rendering images and processing video. A GPU is essentially a **highly parallel processor** with thousands of small cores, making it well-suited for operations like matrix calculations, which are common in graphics rendering and scientific computations.

---
#### MOTHERBOARD

The **motherboard** is the main circuit board that **connects** and allows communication between all the components of the computer, including the CPU, RAM, storage devices, and peripherals. It contains various buses, sockets, and slots that facilitate data transfer and power distribution to these components.

--- 
## 📌HOW DOES THE OPERATING SYSTEM INTERACT WITH THE HARDWARE?

#### FIRMWARE

A **firmware** is a software embedded concretely in the hardware components of the computer (but more generally of a chip based electronic device) in a non-volatile memory slot (ROM Read only memory), it is the "OS" of the hardware, it initialize the hardware and handle its communications with the real OS. 

An example of firmware is the **BIOS/UEFI** (more recent), it is part of the mother board: as soon as you turn on your pc this program initializes and tests the hardware, than it looks for a bootable device such as SSD, HDD ... and there he finds a **bootloader**, a program that loads the OS kernel into the RAM.

---
#### DRIVERS

At this point the OS initialize the user environment, services and **drivers**, they are specific programs that act as intermediary between the OS and the firmwares that are low level programs hard to handle otherwise. You can have two types of drivers: kernel-mode ones, they have more privileges and they act directly on hardware, and user-mode ones, they communicate with hardware by **system calls**, special requests made from the OS to the firmware. 

---
#### OPERATING SYSTEM 

Now we have the highest and most important level of this pyramid: the **OS**, it is divided in the **kernel** (this part manages low level stuff), and the **user space** (here is where the user programs are run, from here accessing to the kernel requires system calls) manages all the resources of the computer and executes many essential tasks: 

1. **Process Management**:

A traditional one core CPU can only do one thing at time so when you deal with many **processes** (programs running on the computer) you have to switch between each task every few microseconds, this procedure is named **multitasking**. Modern computers improved this concept by optimizing dead moments where one component is waiting for information from another or similar situations, thus leading to the concept of **multithreading**. This optimizations are so powerful that a single core today with virtualization can be almost powerful as two single cores. 

The OS **scheduler** handles multitasking and multithreading, it creates processes and gives time slots to each of them. 

2. **Memory Management**

Another important task of the os is handling memory usage and allocation of the single programs and avoiding conflicts between them. Some times the space of the RAM is not enough to handle all the information needed by all the running programs, so what the OS does is **virtualization**. Every program is fooled into thinking of having more space on the RAM than it has but actually rarely accessed information is stored in the hard disk and accessed whenever needed. When you access to data currently in the hard disk you run into a **page fault**. 

<u>Pages</u>
To allow a more non continuous and dynamic allocation of the memory, the RAM is divided into **pages**, each program virtual memory is mapped to specific pages. The virtual memory is continuous: after address x you have x + 1, but actually virtual memory can be linked with non continuous pages in physical memory. 

<u>Segmentation</u>
The memory of each process is divided by purpose, this concept is known as **segmentation**, each segment is used in a specific way and has specific properties: 

- The **text segment** contains the compiled machine code, it is usually read only. 
- The **data segment** stores the global and static variables. 
- The **heap** is used for dynamic memory, its addresses grow upwards. 
- The **stack** is used for local variables, function calls, and return addresses (where to come back on the program once a function has been called), it grows downwards and has limited size. 

<u>Exceptions</u>
A **page fault** is an **exception**, they are special interrupts that need to be handled, when your CPU meets one of these it stops the process and send a request to the OS kernel for an handler. A **segmentation fault** is an exception that occurs when you try to access to memory that is not dedicated to that program or process. 

3. **File and Device Management**

The OS manage the file system, organizing in a specific way each program and ensuring that the access permissions are respected by using file descriptors. It provides **buffers** (a temporary memory area used to store data while it is being transferred from a place to another) to ensure more efficient file reading and writing.  

Another important task of the OS is to interact with hardware through drivers. The OS also ensures security and handles network protocols.

---
# 2️⃣ Networks and Networking

## 📌 WHAT IS A NETWORK?

A network is a system that allows devices such as computers, smartphones, and servers to exchange data. These devices can connect over short or long distances.

A **Local Area Network (LAN)** is used to connect devices within a limited area, such as a home or office. This can be done either with Ethernet cables (wired connection) or using **Wi-Fi**, which is a wireless technology that relies on radio waves transmitted through network interface cards installed in the devices.

On a larger scale, a **Wide Area Network (WAN)** connects multiple LANs across broader geographical regions. The most well-known WAN is the **Internet**, which connects millions of networks and devices worldwide.

---
## 📌 NETWORK COMPONENTS

In a typical home or small business network, several key devices work together to allow communication between machines and provide access to the internet.

A **Switch** connects multiple devices via Ethernet cables within a LAN, allowing them to share data directly. For wireless access, an **Access Point** is used to allow Wi-Fi-enabled devices to communicate with the network.

A **Router** connects the LAN to the outside world, the Internet, by managing and directing traffic between local devices and external servers. However, a router cannot communicate with the **ISP (Internet Service Provider)** on its own; it needs a **Modem**, which connects to the ISP’s infrastructure and provides internet access. Most home routers today are actually combined router-modem devices.

Cellular networks such as 3G, 4G, 5G (That consumes much because it uses high frequency waves)... work with a **RAN (Radio Area Network)**, the ISP builds a network of radio antennas and whenever you want to access the internet you do so by accessing to one of those. Traditional phone calls are made through **PSTN (Public Switched Telephone Network)**, it is a wired network that builds specific connections for each phone call by using switches through the path (once this was done manually). The phone calls can also be done by **VoIP (Voice Over IP)** that uses the internet to communicate instead of PSTN.

---
## 📌 INTERNET ACCESS & IP MANAGEMENT

Every device connected to the internet requires an **IP address**, a unique identifier used to send and receive data. Due to the limited number of IP addresses in the older IPv4 system (32-bit), most ISPs assign only one public IP address to each modem. The first 24 bits of the IP identify the network while the last 8 identify the host, however 00000000 and 11111111 are the **network** and the **broadcast** IPs, the first one identifies the network while the second one is used to send data to all the devices of the LAN at once. 

To manage multiple devices sharing that single IP, the router uses several technologies. 

**DHCP (Dynamic Host Configuration Protocol)** automatically assigns private IP addresses to devices within the LAN, ensuring each one is unique. **NAT (Network Address Translation)** handles the task of mapping these internal private IPs to the single public IP address used on the internet, allowing multiple devices to share the same internet connection seamlessly.

When you enter a website’s domain name in a browser, a system called **DNS (Domain Name System)** translates it into an IP address so your device can find and connect to the correct server. The DNS process involves querying different DNS servers in a hierarchy (root, TLD, authoritative) until the final IP address is found.

The process of accessing a website typically works like this: You enter a domain name (e.g., `example.com`), DNS translates it to an IP address, and your browser sends an **HTTPS** request to that address. The server then responds with the necessary data (HTML, CSS, JavaScript) to render the site in your browser.

---
## 📌 COMMON NETWORK PROTOCOLS

A **protocol** is a set of rules that define how data is transmitted across a network. Different protocols are used for different purposes, and some offer encryption for secure communication.

For loading websites, **HTTP (HyperText Transfer Protocol)** is the standard, but it transmits data in plain text. To improve security, **HTTPS** is used, which adds encryption via **SSL (Secure Sockets Layer)** or the more modern **TLS (Transport Layer Security)**. This ensures that the data exchanged between your browser and a website is private and protected from tampering.

When accessing files on a remote server, **FTP (File Transfer Protocol)** is often used. Secure variants like **FTPS** and **SFTP** add encryption for protection. **SSH (Secure Shell)** is another protocol that provides encrypted access to servers, often used by system administrators.

>- **DNS**, **DHCP**, and **NAT** are also protocols, although they are used internally by networks to manage IP addressing and routing rather than for user-facing services.
>- A **socket** is a software object that ensures a safe communication over a network. (IP + port)

---
**OSI (Open systems interconnection)** is a guide to project network protocols and it develops over several layers. 

| OSI Layer | Layer Name   | Example Protocols                  | Description                                                   |
| --------- | ------------ | ---------------------------------- | ------------------------------------------------------------- |
| 7         | Application  | HTTP, FTP, SMTP, DNS               | User-facing protocols for services like websites, email, etc. |
| 6         | Presentation | SSL/TLS, JPEG, MPEG                | Data translation, encryption, compression                     |
| 5         | Session      | NetBIOS, RPC                       | Manages sessions (start, maintain, end connections)           |
| 4         | Transport    | TCP, UDP                           | Reliable or fast data delivery between devices                |
| 3         | Network      | IP, ICMP, IGMP                     | Routing, addressing, and package forwarding                   |
| 2         | Data Link    | Ethernet, ARP, PPP                 | Transfers data between physically connected devices           |
| 1         | Physical     | Wi-Fi, Ethernet (cable), Bluetooth | Sends raw bits over wires or radio waves                      |

>- **ARP (Address Resolution Protocol)** is a protocol used within a local network to translate the IP addresses into the **MAC's (Media Access Control)** (an unique id that identifies each network card): you send an ARP request to the Broadcast address and if the required device is available it will send its MAC back. 
>- **IP (Internet Protocol)** routes packages into the Internet ensuring that each package is sent to the right IP in the Internet WAN. 
>- **TCP (Transmission Control Protocol)** is a protocol that establishes a **reliable connection** and ensures data is split, sent, received, and reassembled correctly and in order over a network. It’s more about **reliable data delivery** than just efficiency. The idea is that once a package is sent then the recipient sends it back (**ACK** Acknowledgement) so that the sender can check if everything was sent right, if it wasn't you send it once again.
>- Each package has a **PCI (Protocol Control Information)** which contains information about the protocol used and a **SDU (Service Data Unit)** which contains the actual data to transmit. 

---
## 📌 NETWORK SECURITY

To keep data and systems safe, networks often employ a **Firewall**, which acts like a gatekeeper. It monitors incoming and outgoing traffic and filters it based on predefined security rules, blocking suspicious or unauthorized activity.

A **VPN (Virtual Private Network)** provides another layer of protection by creating a secure, encrypted tunnel between your device and a VPN server. This not only prevents eavesdropping (especially on public Wi-Fi networks), but also hides your real IP address. VPNs can also be used to bypass geographic restrictions by making it appear as though you're browsing from another location.

Secure communication protocols like **HTTPS** and **SSH** also contribute to safety by encrypting the data being transmitted, ensuring it cannot be intercepted or altered during transit.

---
# 3️⃣ Servers and Cloud Computing

## 📌WHAT IS A SERVER?

A **server** is a **host** of IT services (databases, websites, etc.) that are therefore "hosted" by the server and can be used by **clients** (users) through networks (LAN, Internet, mobile networks...). **IMPORTANT**: the concept of a server is independent of any physical constraint, for example, the MySQL program for database management is considered a server simply because it provides a "service" of database management.

---
## 📌VIRTUAL, PHYSICAL AND CLOUD SERVERS

A server can be **physical** (essentially a large computer) or **virtual**, meaning that through a software tool (a hypervisor), a virtual space is created that shares part of the hardware with the original server. Another option for hosting services is to use a **cloud server**, meaning remote hosting through companies that offer partitions of their own servers for money.

---
## 📌VIRTUALIZATION AND CONTAINERIZATION

There are different types of virtual servers:  
- A **VM (Virtual Machine)** is essentially a real server with its own operating system. It is assigned a partition of the main server’s hardware and can use resources independently.
- A **VPS (Virtual Private Server)**  is a VM used by a specific user. For example, when a company offers partitions of its own cloud servers, these are VPS.
- A **container** is a lightweight software unit that runs an application along with all its dependencies. Unlike a VM, it does not have a full operating system but shares the host’s kernel, using only the resources necessary for its operation. This makes it faster, more efficient, and *portable* (it can run on any system that supports containers).

>**Docker** and **Kubernetes** are software tools for managing containers on one or more servers.

---
## 📌HOSTING AND WEB SERVERS

A **web server** is software that handles HTTP requests and serves web pages to users. In order to host a web service, you must have a web server. **Apache** and **Nginx** are the two most popular web servers today.

How does a website work on a server?

- A user types the URL in the browser.
- The browser requests the page from the web server (e.g., Apache/Nginx).
- The server sends back the response, i.e., the site’s code (HTML, CSS, JS).
- The browser renders the page on the screen.

---
## 📌DATABASE

A database is an organized system for storing, managing, and retrieving data efficiently, allowing users and applications to access, modify, and analyze information in a structured way.


## 4️⃣ Sistemi Operativi e Terminale

📌 Gestione dei processi e memoria
📌 File system e permessi (chmod, chown)
📌 Comandi base Linux e scripting Bash
📌 Gestione utenti e autenticazione

## 5️⃣ Cybersecurity

---
## 📌Cryptography and SSL Certificates
---

Cryptography is the practice of encrypting texts so that their content doesn't fall into the wrong hands. The process involves two phases: **encryption**, where the **plaintext** becomes **ciphertext**, and **decryption**, the reverse process. Both phases are performed using a key.

#### A bit of history...

The earliest ciphers in history were **substitution ciphers**: a bijection between the alphabet and another alphabet determined which substitutions to make to encrypt the text. A famous example is the **Caesar cipher**, where the bijection was a simple shift. These ciphers are vulnerable due to frequency analysis; in the case of Caesar’s cipher, brute force could be used to find the correct shift.

Another simple cipher is the **transposition cipher**, where all the letters in the plaintext are permuted. In both cases, it was necessary for the sender and recipient to physically meet at least once to exchange the key.

*Mary Stuart (Bloody Mary), Queen of Scots, was imprisoned by Elizabeth I of England. She was plotting to kill Elizabeth and reclaim the throne. She communicated with her conspirators using encrypted (substitution) messages hidden inside beer bottle corks! 🍺 Elizabeth's secret service intercepted and decrypted the messages. Mary was arrested, tried, and sentenced to death.*

Another historical example is **Enigma**, a machine used by the Nazis during WWII to encrypt messages. It featured a series of rotors that constantly changed the substitution bijection. Enigma was ultimately decrypted thanks to early electromechanical machines developed by Alan Turing.

#### Modern cryptography

There are several types of cryptography:

- **Symmetric cryptography**: both parties use the same key to encrypt and decrypt messages. However, both must know the key in advance.

The most common symmetric algorithm today is **AES** (an evolution of DES), which breaks the plaintext into 128-bit blocks and applies a series of mathematical operations to encrypt each block.

- **Asymmetric cryptography**: each user has two keys—a public key and a private key. When I want to send a message to someone, I encrypt it using their public key. Only their private key can decrypt it. Since asymmetric cryptography is heavy and slow, it's usually only used to exchange the key for a symmetric cipher.

The first known asymmetric algorithm is **RSA**. Two large prime numbers are generated and multiplied, $p*q = n$. Then, a number $e$ is chosen such that $(e, \phi(n)) = 1$, and $d = e^{-1} \mod(\phi(n))$ is calculated.

Now the public key is $(e, n)$ and the private key is $(d, n)$. If a sender wants to encrypt a message $m$, they convert $m$ into a number and compute $m^e \mod(n)$. The receiver, knowing $d$, can easily decrypt it. The security of RSA lies in the difficulty of factoring large numbers—although quantum computers could potentially break RSA.

Today, more efficient asymmetric algorithms exist, such as those based on **elliptic curves**.

- **Hashing**: Hashing is used in various cybersecurity processes.

For example, when storing **passwords**, websites don’t save the actual passwords for security reasons. Instead, they store the **hashed** version of the password. Every time you log in, the site hashes your input and checks it against the stored hash.

Another important application of hashing is **digital signatures**, often combined with asymmetric encryption:

Digital signatures work like this:

1️⃣ The sender computes the hash of the message.  
2️⃣ The hash is encrypted with the sender’s private key.  
3️⃣ The signed message is sent.  
4️⃣ The recipient decrypts the hash using the sender’s public key.  
5️⃣ The recipient computes the hash of the received message and compares it to the decrypted one.

Hashing ensures two things: the hash is lightweight and easier to transmit, and it ensures **message integrity**—if the message has been tampered with, the hashes won't match.



📌 Autenticazione a due fattori (2FA)
📌 Attacchi informatici e protezioni
📌 Penetration testing e Ethical Hacking

## 6️⃣ Hardware e Architettura dei Computer

📌 Come funziona una CPU
📌 Memoria cache, RAM e paging
📌 SSD vs HDD e gestione dello storage
📌 Architetture x86 vs ARM





// roba da aggiungere crypto 
✅ Diffie-Hellman: lo scambio sicuro delle chiavi

    Prima di usare una cifratura simmetrica, dobbiamo scambiarci una chiave. Il metodo Diffie-Hellman permette a due parti di accordarsi su una chiave condivisa senza trasmetterla in chiaro.
    Si basa sulla difficoltà del problema del logaritmo discreto.

✅ TLS (SSL) e certificati digitali

    TLS (Transport Layer Security) è ciò che protegge HTTPS. Usa una combinazione di crittografia asimmetrica (per lo scambio della chiave) e simmetrica (per la comunicazione).
    I certificati SSL/TLS sono rilasciati da Certificate Authorities (CA) per garantire che un sito sia autentico.

✅ Attacchi ai sistemi crittografici

    Man-in-the-Middle (MITM): un attaccante intercetta la comunicazione tra due parti.
    Padding Oracle Attack: sfrutta la gestione degli errori nei sistemi basati su padding (es. CBC).
    Attacchi ai certificati: Se un'entità non affidabile rilascia un certificato falso, può spacciarsi per un sito legittimo (attacco PKI).


// OVERKILL, TO fix 
## CHAPTER 34: NP-COMPLETENESS

### P, NP, NP-complete, NP-hard, co-NP

*To ease the classifications of problems we define everything from now on for decision problems, these are problems where the solution is only yes or no. Every optimization problem can be reduced to a decision one by stating: can we get a lower/higher value than this?*

A problem is classified **P** if it is solvable in polynomial time, that is the complexity to solve it is O(polinomyal function). A problem is **NP** if given a solution you can compute if it is correct or not in polynomial time. 

A problem X is **NP-complete** if every problem in NP can be reduced to it in polynomial time. 

A problem X is **NP hard** if every NP problem can be reduced to X in polynomial time. Note that given such a definition every NP complete problem is NP hard but the reverse is not true, in fact it can exist a problem that is NP hard but is not NP, that is a problem for which a polynomial verification is not known.

**co-NP** problems are problems for which we have a polynomial verification alg of the inputs that are not producing a 1 result. Surely P is a subset of NP intersecated with co-NP but we still don't know if NP = co-NP. 

**Note well:** we define the classes of problems where the variable respect to witch we compute the complexity is the length of the binary string of the input so for example checking if a number n is prime takes sqrt(n) that pratically is 2^(1/2 * logn) so it is actually esponential respect to logn. (Actually for this problem a polynomial alg exists).


#### Reductions 

If you have two problems A (complexity unknown) and B (complexity known) and you have an algorithm that converts problem A into problem B in polynomial time ensuring that both A transformed and B have equivalent outputs, than you can classify the complexity of . In fact if B is P than also A is P. Now flipping the problem and supposing that A is NP-complete while B is unknown if we can reduce in polynomial time A to B than B must be also NP. 


### Formal definition of P and NP

#### P and Encoding

Firstly we love polynomial algs because they often have low degree, they do not depend on the compute model and if A, B are polynomial and one calls the other a constant number of times then everything stays polynomial.

An **abstract problem** is a given relation between a domain of istances and a codomain of outputs. From a starting abstract problem we use encoding to transform it into a **concrete problem**: we encode the instances of the domain into binary strings so that we can use a computer to solve the problem. Here the **encoding** matters: if we use an unary encoding we add a factor k to the algorithm so we should use a reasonable encoding. Two encodings are **polynomially related** if it exists an algorithm that moves from one to the other in polynomial time. 

#### Alphabet and languages

- An alphabet Σ is a finite set of symbols (e.g., Σ={0,1}).
- A language L over Σ is a set of finite strings built from the symbols of Σ, i.e., L ⊆ Σ*.
- A decision problem can be represented as a language, where each string x belongs to the language L if the answer to the problem for input x is "yes".

#### Algorithms and acceptance

- An algorithm accepts a string x if, given input x, it outputs 1.
- The language accepted by an algorithm A is the set of strings for which the algorithm outputs 1:  
  L = {x ∈ Σ* | A(x) = 1}.
- An algorithm decides L if it always returns 1 for x ∈ L and 0 for x ∉ L, i.e., it behaves correctly for all strings.
  
#### Difference between acceptance and decision

- Accepting ≠ deciding: an algorithm may accept x ∈ L, but if x ∉ L, it may never halt.
- To be in P, the algorithm must decide the language: it must always halt and provide the correct answer.

#### Formal definition of class P and NP

The class P is the set of languages (i.e., decision problems) for which there exists an algorithm that decides the language in polynomial time with respect to the input length. Note that we can also easily define formally a verification algorithm, and from this NP is the class of problems for which it exists a verification alg that runs in polynomial time. 

**Important Theorem**: If a language is accepted in polynomial time, then it is also decidable in polynomial time. This justifies that we can use the notion of "acceptance" to define P because, in the end, we can construct an algorithm that simulates the acceptor and forces it to decide within a time limit.


### The first NP-complete

The first NP-complete problem will be the one from which we will try to reduce to other problems to prove they are NP-complete: it is the **CIRCUIT SAT** problem that given a boolean circuit with logical gates requires to tell if it exists a n-uple of boolean values to assign to each variable in the circuit so that the final output is one. From this problem reduction is used to prove that other problems are NP-complete. 
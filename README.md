# DNA-Analyzer-Project

An extensive OOP project, with the goal of creating a software for manipulating DNA sequences.
Designed to handle very large amounts of memory efficiently. A combination of Design Patterns and efficient data structures using C++.

The goal of this system is to load, analyze, manipulate and save DNA sequences. 
DNA sequences are composed of four types of nucleotides: The nucleotides are marked A (Adenine), G (Guanine), C (Cytosine) and T (Thymine). 
A full DNA molecule usually consists of two strands, connected to each other in base-pair connections: As with Ts, and Cs with Gs.
Three successive nucleotides generate a codon, which might be chemically "read" in various ways. 

The system will interact with the user through a CLI (Command Line Interface) that uses the standard I/O.
Using that interface, the user will be able to load DNA sequences from files, to analyze them, to manipulate them
(e.g., by extracting sequence slices or by modifying the sequence), and to store modified sequences and reports

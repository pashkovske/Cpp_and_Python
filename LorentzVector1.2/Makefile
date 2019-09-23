all: link

link: main.o LorentzVector.o
	g++ main.o LorentzVector.o
main.o:
	g++ -c main.cpp

LorentzVector.o:
	g++ -c LorentzVector.cpp

clean:
	rm main.o LorentzVector.o

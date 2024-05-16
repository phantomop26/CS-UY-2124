/*
  rec10_start.cpp
  Starting code 24S
 */


#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
    virtual ostream& print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Instrument& instr) {
        instr.print(os);
        return os; }
private:
};
void Instrument::makeSound() const{
    cout<<"to make a sound";
}                     
class Brass: public Instrument {
public:
    Brass(unsigned mouthpieceSize): mouthpieceSize(mouthpieceSize) {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "... blow on a mouthpiece of size " << mouthpieceSize << endl;
    }
protected:
    unsigned getMouthpieceSize() const {
        return mouthpieceSize;  
    }
private:
    unsigned mouthpieceSize;
};

class String: public Instrument {
public:
    String(unsigned pitch): pitch(pitch) {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "... bow a string with pitch " << pitch << endl;
    }
protected:
    unsigned getPitch() const {
        return pitch;
    }
private:
    unsigned pitch;
};

class Percussion: public Instrument {
public:
    Percussion() {}
    void makeSound() const {
        Instrument::makeSound();
        cout << "... hit me!" << endl;
    };
private:
};

class Trumpet: public Brass {
    public:
        Trumpet(unsigned mouthpieceSize): Brass(mouthpieceSize) {}
        void play() const {
            cout << "Toot";
        }
        ostream& print(ostream& os) const {
            os << "Trumpet: " << getMouthpieceSize();
            return os;
        }
    private:
};

class Trombone: public Brass {
public:
    Trombone(unsigned mouthpieceSize): Brass(mouthpieceSize) {}
    void play() const {
        cout << "Blat";
    }
    ostream& print(ostream& os) const {
        os << "Trombone: " << getMouthpieceSize();
        return os;
    }
private:
};

class Violin: public String {
public:
    Violin(unsigned pitch): String(pitch) {}
    void play() const {
        cout << "Screech";
    }
    ostream& print(ostream& os) const {
        os << "Violin: " << getPitch();
        return os;
    }
private:
};

class Cello: public String {
public:
    Cello(unsigned pitch): String(pitch) {}
    void play() const {
        cout << "Squawk";
    }
    ostream& print(ostream& os) const {
        os << "Cello: " << getPitch();
        return os;
    }
private:
};

class Drum: public Percussion {
public:
    Drum() {}
    void play() const {
        cout << "Boom";
    }
    ostream& print(ostream& os) const {
        os << "Drum";
        return os;
    }
private:
};

class Cymbal: public Percussion {
public:
    Cymbal() {}
    void play() const {
        cout << "Crash";
    }
    ostream& print(ostream& os) const {
        os << "Cymbal";
        return os;
    }
private:
};

class MILL {
public:
    MILL() {
        numInstruments = 0;
    }

    void receiveInstr(Instrument& instr) {
        numInstruments++;
        instr.makeSound();
        for (size_t i = 0; i < instruments.size(); ++i) {
            if (instruments[i] == nullptr) {
                instruments[i] = &instr;
                return;
            }
        }
        instruments.push_back(&instr);
    }

    Instrument* loanOut() {
        numInstruments--;
        for (size_t i = 0; i < instruments.size(); ++i) {
            if (instruments[i] != nullptr) {
                Instrument* result = instruments[i];
                instruments[i] = nullptr;
                return result;
            }
        }
        return nullptr; // no instruments available
    }

    void dailyTestPlay() const {
        for (const Instrument* instr : instruments) {
            if (instr != nullptr) {
                instr->makeSound();
            }
        }
    }

    friend ostream& operator<<(ostream& os, const MILL& mill) {
        if (mill.numInstruments == 0) {
            os << "The MILL has the following instruments: None" << endl;
        }
        else {
            os << "The MILL has the following instruments:" << endl;
            for (const Instrument* instr : mill.instruments) {
                if (instr != nullptr) {
                    os << "\t" << *instr << endl;
                }
            }
        }
        return os;
    }

private:
    vector<Instrument*> instruments;
    int numInstruments;
};

// 
// Musician class as provided to the students. Requires an Instrument class.
// 
class Musician {
public:
    Musician(const string& name): instr(nullptr), name(name) {}

    // acceptInstr takes in an instrument for the Musician to later play.
    //  "loses" any instrument that it used to have.
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    // giveBackInstr: gives the instrument that the Musicial was holding "back"
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    // testPlay: testing out my instrument
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << name << " has no instr\n";
    }

    // play: play the instrument

    //   Not making it const so that Instrument::play method does not
    //   need to be const. Allows the instrument to be modifed in the
    //   process of being played.
    void play() {
        if (instr) instr->play();
        // Don't do anything if we don't have an instrument.
    }
private:
    Instrument* instr;
    string name;
};

class Orch {
public:
    void addPlayer(Musician& musician) {
        musicians.push_back(&musician);
    }

    void play() const {
        for (Musician* musician : musicians) {
            musician->play();
        }
        cout << "\n";
    }
private:
    vector<Musician*> musicians;
};


int main() {

    //
    // PART ONE
    //
    cout << "P A R T  O N E\n";

    cout << "Define some instruments ---------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    cout << "Define the MILL -----------------------------------------------\n";
    MILL mill;
    cout << "The MILL before adding instruments:\n" << mill << "\n\n";

    cout << "Put the instruments into the MILL -----------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    cout << "\nThe MILL after adding some instruments:\n" << mill << "\n\n";

    cout << "Daily test ----------------------------------------------------\n"
        << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;

    cout << "Define some Musicians------------------------------------------\n";
    Musician harpo("Harpo");
    Musician groucho("Groucho");

    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();	 // Groucho doesn't have an instrument yet.

    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;

    groucho.testPlay();
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();
    harpo.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL after giving out some instruments:\n";
    cout << mill << "\n\n";

    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
    mill.receiveInstr(*groucho.giveBackInstr());

    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());
    cout << endl;

    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL at the end of Part One:\n";
    cout << mill << endl;

    //
    // PART TWO
    //
    cout << "\nP A R T  T W O\n";

    Musician bob("Bob");
    Musician sue("Sue");
    Musician mary("Mary");
    Musician ralph("Ralph");
    Musician jody("Judy");
    Musician morgan("Morgan");

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    cout << endl << mill << endl;

}


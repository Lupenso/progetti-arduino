// includo la libreria per usare le note
#include "pitches.h"

// Dichiaro diverse variabili
int pinLedRosso = 13;
int pinLedVerde = 12;
int pinBuzzer = 2;

String sceltaPorta;

bool haChiavePorta2 = false;
bool haChiavePorta3 = false;

void setup()
{
  // Inizializzo il serial monitor
  Serial.begin(9600);

  pinMode(pinLedRosso, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  // Inzio spiegando la storia
  Serial.println("Ti ritrovi in una stanza, ma non ti ricordi come ci sei arrivato.\nDavanti a te ci sono 3 porte,\ncon una con la scritta libertà");
  // Chiamo la funzione drawDoor con argomento 0 (tutte le porte chiuse)
  drawDoor("0");

// Inizio un label
scegliPorta:
  // Semplice logica per la scelta della porta + controllo che l'utente abbia le chiavi 
  Serial.println("Quale porta scegli?");
  sceltaPorta = leggiRisposta();
  if (sceltaPorta == "1\n") {
    if (haChiavePorta2) {
      Serial.println("\nSei già stato qui, perchè tornare?");
      goto scegliPorta;
    }
    primaPorta();
    goto scegliPorta;
  } else if (sceltaPorta == "2\n") {
    if (haChiavePorta3) {
      Serial.println("\nSei già stato qui, perchè tornare?");
      goto scegliPorta;
    }
    if (haChiavePorta2) {
      secondaPorta();
      goto scegliPorta;
    } else {
      Serial.println("Quella porta sembra essere bloccata");
      goto scegliPorta;
    }
  } else if (sceltaPorta == "3\n") {
    if (haChiavePorta3) {
      terzaPorta();
    } else {
      Serial.println("Quella porta sembra essere bloccata");
      goto scegliPorta;
    }
  }
}

void loop()
{

}

// Funzione che accende e/o spegne il led che dai negli argomenti
void illuminaLed(int luceDaIlluminare, int luceDaSpegnere) {
  // Accende la luce che aggiungi negli argomenti
  digitalWrite(luceDaIlluminare, HIGH);

  // Se il secondo argomento è uguale a zero, non spegni nessuna luce
  if (luceDaSpegnere != 0) {
    // Se è diverso da zero, spegne la luce che hai inserito nel secondo argomento
    digitalWrite(luceDaSpegnere, LOW);
  }
}

// Funzione che legge l'input dell'utente quando serve e lo ritorna
String leggiRisposta() {
  while (Serial.available() == 0) {

  }
  String x = Serial.readString();
  return x;
}

// Funzione per tutta la logica della prima porta
void primaPorta()
{
  Serial.println("Hai scelto la porta uno e riesci ad aprirla");
  drawDoor("1");

  // Illumina il led
  illuminaLed(pinLedVerde, pinLedRosso);
  delay(500);
  illuminaLed(0, pinLedVerde);
  Serial.println("Ti ritrovi davanti ad una scatola e per aprirla devi rispondere ad un indovinello");
  Serial.println("Quando è iniziata la prima guerra mondiale in italia?");

sceltaData:
  Serial.println("");
  Serial.println("a: 1914");
  Serial.println("b: 1915");
  Serial.println("c: 1918");

  Serial.println("Quale risposta scegli?");
  String sceltaData = leggiRisposta();
  if (sceltaData != "b\n") {
    Serial.println("Hai sbagliato, ritenta");
    // Illumina il led + fai un suono
    illuminaLed(pinLedRosso, pinLedVerde);
    playSound(2);
    illuminaLed(0, pinLedRosso);
    goto sceltaData;
  } else {
    Serial.println("Bravo, hai scelto saggamente e hai trovato un scintillante chiave nella scatola");
    haChiavePorta2 = true;
    // Illumina il led + fai un suono
    illuminaLed(pinLedVerde, pinLedRosso);
    playSound(1);
    illuminaLed(0, pinLedVerde);
    Serial.println("Torni indietro e ti ritrovi nuovamente davanti alle 3 porte");
    drawDoor("1");
  }
}

// funzione che trattiene tutta la logica per la seconda porta
void secondaPorta()
{
  Serial.println("Grazie alla chiave che hai ritrovato apri anche la seconda porta");
  drawDoor("2");

  // Illumina il led
  illuminaLed(pinLedVerde, pinLedRosso);
  delay(500);
  illuminaLed(0, pinLedVerde);

  Serial.println("Ti ritrovi davanti ad un lungo corridoio bloccato da una porta chiusa");
  Serial.println("Alla fine del corridoio c'è una teca con la chiave per la tua libertà");

  Serial.println("");
  Serial.println("Devi risolvere un ulteriore semplice indovinello");

sceltaCapitale:
  Serial.println("Quale è la capitale del Canada?\n");
  Serial.println("a: Vancouver");
  Serial.println("b: Toronto");
  Serial.println("c: Ottawa");

  Serial.println("Quale risposta scegli?");
  String sceltaCapitale = leggiRisposta();
  if (sceltaCapitale != "c\n") {
    Serial.println("Hai sbagliato, ritenta");
    // Illumina il led + fai un suono
    illuminaLed(pinLedRosso, pinLedVerde);
    playSound(2);
    illuminaLed(0, pinLedRosso);
    goto sceltaCapitale;
  } else {
    Serial.println("Bravo, hai scelto saggamente e hai trovato un scintillante chiave nella teca");
    haChiavePorta3 = true;
    // Illumina il led + fai un suono
    illuminaLed(pinLedVerde, pinLedRosso);
    playSound(1);
    illuminaLed(0, pinLedVerde);
    Serial.println("Torni indietro e ti ritrovi nuovamente davanti alle 3 porte");
    drawDoor("2");
  }
}

// funzione che contiene tutta la logica per la terza porta
void terzaPorta()
{
  Serial.println("Grazie alla chiave che hai ritrovato apri anche la terza porta\n");
  drawDoor("3");

  Serial.println("Attraversi la terza porta e ti ritrovi davanti ad una via trafficata");
  Serial.println("La porta alle tue spalle si chiude per sempre\n");
  drawDoor("ff");
  Serial.println("Sei finalmente libero");
  // Illumina il led + fai un suono
  illuminaLed(pinLedVerde, pinLedRosso);
  playSound(1);
  illuminaLed(0, pinLedVerde);
}




// Una funzione che permette di stampare a schermo le porte 
void drawDoor(String qualeAprire) {

  // tutte le porte chiuse
  if (qualeAprire == "0") {
    Serial.println(R"(
     %%%%%%%%%%%%%%%%(            %%%%%%%%%%%%%%%%(        #%%%%%%%%%%%%%%(%(   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%%%%%%%%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%#%%%%#%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%%%%%%%%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%#%%%%#%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%%%%%%%%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&% .      (%&%%%%%%%%%%%%%%(   
     (&%%%%%%%%%%%%,&%            (&%%%%%%%%%%%%,&%        #(&%%%%%%%%%%%%.%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%%%%%%%%#%%%%   
     %&%%%%#%%%%%%%%&%            %&%%%%#%%%%%%%%&%        #%&%%%%%%%%%%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%&%%%%%#%%%%%%%%%   
     %&%%%%%%%%%#%%%&%            %&%%%%%%%%%#%%%&%        #%&%%%%%%%%%%%%%%%   
     %&%%%%%%%%%%%%%&%            %&%%%%%%%%%%%%%&%        #%#%%%%%%%%%%%%%%%   
     %&%%%%%%%%%%%%%&( .         .%&%%%%%%%%%%%%%&(.       ((&%%%%%%%%%%%%(%(   
  ..,%@*************(%,          ,%(*************/%,       %%#*************%%.  
      )");
  }

  // una porta aperta
  if (qualeAprire == "1") {
    Serial.println(R"(
     %%%%%%%%%%%%%%%%%%        #%%%%%%%%%%%%%%%%%         %%%%%%%%%%%%%%#%(     
     %&%%%%%%        %%        %%%%%%%%%%%%%%%&%%         %&%%%%%%%%%%%%%%%     
     %&%%%%%%        %%        %%%%%%%%%%%%%%%%%%         %&%%%%%%%%#%%%%%%     
     &&%%%%%%        %%        %%%%%%%%%%%%%%%%%%         %&%%%%%%%%%%%%%%%     
     %&%%%%%%        %%        %%%%%%%%%%%%%%%%%%         %&%%%#%%%%%%%%%%%     
     &&%%%%%%        %%        %%%%%%%%%%%%%%%%%%         %&%%%%%%%%%%%%%%%     
     ####%%%%        %#        (%%%%%%%%%%%%%%&%(         %&%%%%%%%%%%%%%%(     
     &&%%%%%%        %%        %%%%%%%%%%%%%%%&%%         (&%%%%%%%%%%%%,%%     
     &&%%%%%%        %%        %%%%#%%%%%%%%%%&%%         %&%%%%%%%%%%%%%%%     
     %&%%%%%%        %%        %%%%%%%%%%%%%%%&%%         %&%%%%%%%%%%%%%%%     
     &&%%%%%%        %%        %%%%%%%%%#%%%%%&%%         %&%%%%%%%%%%%%%%%     
     &&%%%%%%        %%        %%%%%%%%%%%%%%%&%%         %&%%%%%%%%%%%%%%%     
     &&(%%%%%        %%        %%%%%%%%%%%%%%%&%%         %%%%%%%%%%%%%%%%%     
     %&%%%%%%        %%       .%%&%%%%%%%%%%%%&((..       %&%%%%%%%%%%%%#%( .   
     ,*/&%%%%                 .%&**************%%.       ,%#*************%%.    
     ....,*&%                                                                 
      )");
  }

  // due porte aperte
  if (qualeAprire == "2") {
    Serial.println(R"(
           %                           %                  %%%%%%%%%%%%%%#%(     
     %%%%%%%%%%%%%%(             %%%%%%%%%%%%%%(          %&%%%%%%%%%%%%%%%     
     %&%%%%%       %             &&%%%#%       %          %&%%%%%%%%#%%%%%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%%%%%%%%%%%%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%#%%%%%%%%%%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%%%%%%%%%%%%%     
     %#%#%%%       %.            &#%%%%%       %          %&%%%%%%%%%%%%%%(     
     %&%%%%/       %             &&%%%%*       %          (&%%%%%%%%%%%%,%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%%%%%%%%%%%%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%%%%%%%%%%%%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%%%%%%%%%%%%%     
     %&%%%%%       %             &&%%%%%       %          %&%%%%%%%%%%%%%%%     
     %#%%%%%       %             &%%%%%%       %          %%%%%%%%%%%%%%%%%     
   ..,*/&%%%..                 ..,*/&%%%..                %&%%%%%%%%%%%%#%( .   
      ....,%.                     ....,&.                ,%#*************%%.   
      )");
  }
  // tutte le porte aperte
  if (qualeAprire == "3") {
    Serial.println(R"(
                %                                                                    
     %%%%%%%%%%%%%%(                  %%                          %%/           
     %&%%%%%       %             %%%%%%%%%%%%%%%             #%%%%%%%%%%%%%%.   
     %&%%%%%       %             &&%%%%%       %             %&%%%%%/      %    
     %&%%%%%       %             &&%%%%%       %             %&%%%%%/      %.   
     %&%%%%%       %             &&%%%%%       %             %&%%%%%/      %.   
     %#%#%%%       %.            &&%%%%%       %             %&%%%%%/      %    
     %&%%%%/       %             &##%%%*       %             %#%%%%,(      %    
     %&%%%%%       %             &&%%%%*       %             %&%%%%*(      %.   
     %&%%%%%       %             &&%%%%#       %             %&%%%%#/      %.   
     %&%%%%%       %             &&%%%%%       %             %&%%%%%/      %.   
     %&%%%%%       %             &&%%%%%       %             %&%%%#%/      %.   
     %#%%%%%       %             &&(%%%%       %             %&(%%%%/      %.   
   ..,*/&%%%..                   &&%%%%%.      %             %&%%%%%(      %.   
      ....,%.                  ..,,*(&%%...                ..,,*(&%%(..         
                                      .,                          .,,         
      )");
  }

  // Solo una porta chiusa
  if (qualeAprire == "ff") {
    Serial.println(R"(
      #%%%%%%%%%%%%%%(%(   
      #%&%%%%%%%%%%%%%%%   
      #%&%%%#%%%%#%%%%%%   
      #%&%%%%%%%%%%%%%%%   
      #%&%%%#%%%%#%%%%%%   
      #%&%%%%%%%%%%%%%%%   
      (%&%%%%%%%%%%%%%%(   
      #(&%%%%%%%%%%%%.%%   
      #%&%%%%%%%%%%#%%%%   
      #%&%%%%%%%%%%%%%%%   
      #%&%%%%%#%%%%%%%%%   
      #%&%%%%%%%%%%%%%%%   
      #%#%%%%%%%%%%%%%%%   
      ((&%%%%%%%%%%%%(%(   
      %%#*************%%.
    )");
  }

}

// funzione che permette di suonare due tipi di suoni diversi, in base agli argomenti
void playSound(int sceltaSuono) {
  // Suona il suono della vittoria
  if (sceltaSuono == 1) {
    tone(2, NOTE_E6, 125);
    delay(130);
    tone(2, NOTE_G6, 125);
    delay(130);
    tone(2, NOTE_E7, 125);
    delay(130);
    tone(2, NOTE_C7, 125);
    delay(130);
    tone(2, NOTE_D7, 125);
    delay(130);
    tone(2, NOTE_G7, 125);
    delay(125);
    noTone(2);
  }
  // Fai partire il suono della sconfitta
  if (sceltaSuono == 2) {
    tone(2, NOTE_GS5, 100);
    delay(300);
    tone(2, NOTE_AS4, 100);
    delay(300);
    tone(2, NOTE_FS3, 100);
    delay(300);
    tone(2, NOTE_CS2, 850);
    delay(300);
    tone(2, NOTE_E1, 850);
    delay(800);
    noTone(2);

    delay(1000);
  }
}

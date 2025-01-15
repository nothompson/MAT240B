#include "everything.h"
#include <iostream>
using namespace std;

// int main(int argc, char* argv[]) {
//   float phase = 0;
//   for (float note = 127; note > 0; note -= 0.001) {
//     float frequency = mtof(note);
//     float v = sin(phase);
//     mono(v * 0.47);
//     phase += 2 * pi * frequency / SAMPLE_RATE;
//     if (phase > 2 * pi)  //
//       phase -= 2 * pi;
//   }
// }

//impulse train

// int main(int argc, char* argv[]) {
//   float phase = 0;
//   float decay = 1;
//   float Nyquist = SAMPLE_RATE / 2;
//   float v = 0;
//   for (float time = 0; time < SAMPLE_RATE * 2; ++time) {
//     float frequency = mtof(60);
//     // float v = 0.0;
//     for (int harmonic = 1; harmonic * frequency < Nyquist; ++harmonic){
//         v += (sin(phase * harmonic));
//         // v = v / harmonic;
//     }

//     mono(v * 0.3);
//       // mono(v * (0.07 * decay));
//       //         if (decay > 0) {
//       //         decay -= 0.00002;
//       //         if (decay < 0) decay = 0; 
//       //     }
//     phase += 2 * pi * frequency / SAMPLE_RATE;
//     if (phase > 2 * pi)  //
//       phase -= 2 * pi;
//   }
// }

// impulse sweep

// int main(int argc, char* argv[]) {
//   float phase = 0;
//   float decay = 1;
//   float Nyquist = SAMPLE_RATE / 2;
//   float v = 0;
//   for (float note = 80; note > 0; note -= 0.0005) {
//     float frequency = mtof(note);
//     for (int harmonic = 1; harmonic * frequency < Nyquist; ++harmonic){
//         v += (sin(phase * harmonic));
//         // v = v / harmonic;
//     }

//     mono(v * 0.3);
//       // mono(v * (0.07 * decay));
//       //         if (decay > 0) {
//       //         decay -= 0.00002;
//       //         if (decay < 0) decay = 0; 
//       //     }
//     phase += 2 * pi * frequency / SAMPLE_RATE;
//     if (phase > 2 * pi)  //
//       phase -= 2 * pi;
//   }
// }



//sawtooth

// int main(int argc, char* argv[]) {
//     float phase = 0.0f;   
//     float frequency = mtof(60);          
//     float Nyquist = SAMPLE_RATE / 2;     
//     float v = 0.0f;

//     for (int time = 0; time < SAMPLE_RATE * 2; ++time) {
//         for (int harmonic = 1; harmonic * frequency < Nyquist; ++harmonic) {
//             v += (1.0f / harmonic) * sin(harmonic * phase); 
//         }

//         v *= 0.5f;

//         mono(v * 0.3f);

//         phase += 2.0f * pi * frequency / SAMPLE_RATE;

//         if (phase >= 2.0f * pi) {
//             phase -= 2.0f * pi;
//         }
//     }
// }

//saw sweep

// int main(int argc, char* argv[]) {
//     float phase = 0.0f;           
//     float Nyquist = SAMPLE_RATE / 2;     
//     float v = 0.0f;
//     for (float note = 127; note > 0; note -= 0.001) {
//       float frequency = mtof(note);  
//         for (int harmonic = 1; harmonic * frequency < Nyquist; ++harmonic) {
//             v += (1.0f / harmonic) * sin(harmonic * phase); 
//         }

//         v *= 0.5f;

//         mono(v * 0.3f);

//         phase += 2.0f * pi * frequency / SAMPLE_RATE;

//         if (phase >= 2.0f * pi) {
//             phase -= 2.0f * pi;
//         }
//     }
// }

//square

// int main(int argc, char* argv[]) {
//     float phase = 0.0f;   
//     float frequency = mtof(60);          
//     float Nyquist = SAMPLE_RATE / 2;    
//     float v = 0.0f;
//     // float scalar = 4.0f / pi;

//     for (int time = 0; time < SAMPLE_RATE * 2; ++time) {
//         for (int harmonic = 1; harmonic * frequency < Nyquist; harmonic += 2) {
//             v += (1.0f / harmonic) * sin(harmonic * phase); 
//         }

//         v *= fmod((4.0f / pi), 1); //breaks if v amplitude exceeds 1..??

//         mono(v * 0.85f);

//         phase += 2.0f * pi * frequency / SAMPLE_RATE;

//         if (phase >= 2.0f * pi) {
//             phase -= 2.0f * pi;
//         }
//     }
// }

//square sweep

// int main(int argc, char* argv[]) {
//     float phase = 0.0f;         
//     float Nyquist = SAMPLE_RATE / 2;    
//     float v = 0.0f;
//     // float scalar = 4.0f / pi;

//     for (float note = 80; note > 0; note -= 0.0005) {
//       float frequency = mtof(note);   
//         for (int harmonic = 1; harmonic * frequency < Nyquist; harmonic += 2) {
//             v += (1.0f / harmonic) * sin(harmonic * phase); 
//         }

//         v *= fmod((4.0f / pi), 1); //breaks if v amplitude exceeds 1..??

//         mono(v * 0.85f);

//         phase += 2.0f * pi * frequency / SAMPLE_RATE;

//         if (phase >= 2.0f * pi) {
//             phase -= 2.0f * pi;
//         }
//     }
// }

// triangle

// int main(int argc, char* argv[]) {
//     float phase = 0.0f;   
//     float frequency = mtof(60);          
//     float Nyquist = SAMPLE_RATE / 2;     
//     float v = 0.0f;

//     for (int time = 0; time < SAMPLE_RATE * 2; ++time) {
//         for (float harmonic = 1; harmonic * frequency < Nyquist; harmonic+= 2) {

//             float n = (harmonic - 1) / 2; //cannot multiply or divide this or it breaks..? 
//             v += (pow(-1.0f, n) / (harmonic * harmonic)) * sin(harmonic * phase); 

//             // v += (1.0f / (harmonic * harmonic)) * sin(harmonic * phase); 
            
//         }

//         v *= (8.0f / pow(pi,2));
//         // v *= fmod((8.0f / pow(pi, 2)), 1); //if v exceeds 1 in this line it breaks, so i decided to wrap it but I know this is not achieving the right leveling

//         mono(v * 0.1f);

//         phase += 2.0f * pi * frequency / SAMPLE_RATE;

//         if (phase >= 2.0f * pi) {
//             phase -= 2.0f * pi;
//         }
//     }
// }
// triangle sweep

int main(int argc, char* argv[]) {
    float phase = 0.0f;          
    float Nyquist = SAMPLE_RATE / 2;     
    float v = 0.0f;

    for (float note = 127; note > 0; note -= 0.001) {
       float frequency = mtof(note);   
        for (float harmonic = 1; harmonic * frequency < Nyquist; harmonic+= 2) {

            float n = (harmonic - 1) / 2; //cannot multiply or divide this or it breaks..? 
            v += (pow(-1.0f, n) / (harmonic * harmonic)) * sin(harmonic * phase); 

            // v += (1.0f / (harmonic * harmonic)) * sin(harmonic * phase); 
            
        }

        v *= (8.0f / pow(pi,2));
        // v *= fmod((8.0f / pow(pi, 2)), 1); //if v exceeds 1 in this line it breaks, so i decided to wrap it but I know this is not achieving the right leveling

        mono(v * 0.1f);

        phase += 2.0f * pi * frequency / SAMPLE_RATE;

        if (phase >= 2.0f * pi) {
            phase -= 2.0f * pi;
        }
    }
}


//trying to get piano like tone

// int main(int argc, char* argv[]) {
//   float phase = 0;
//   float frequency = mtof(60);
//   for (float decay = 1.0; decay > 0; decay -= 0.00001) {
//     float o0 = sin(phase * 1) * 0.9;
//     float o1 = sin(phase * 2) * 0.1;
//     float o2 = sin(phase * 3) * 0.5;
//     float o3 = sin(phase * 4) * 0.65;
//     float o4 = sin(phase * 5) * 0.45;
//     float o5 = sin(phase * 6) * 0.2;
//     float o6 = sin(phase * 7) * 0.18;
//     float o7 = sin(phase * 8) * 0.1;

//     float overtones = o0 + o1 + o2 + o3 + o4 + o5 + o6 + o7;
//     float v = overtones;

//     v*= decay;
//     mono(v * 0.5);
//     phase += 2 * pi * frequency / SAMPLE_RATE;
//     if (phase > 2 * pi)  //
//       phase -= 2 * pi;
//   }
// }

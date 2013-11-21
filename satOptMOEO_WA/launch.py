import os
import subprocess
subprocess.call(['module swap GCC  GCC/4.7.3'],shell=True)
#subprocess.call(['gcc --version'],shell=True)
subprocess.call(['./satOptMOEO @param'],shell=True)

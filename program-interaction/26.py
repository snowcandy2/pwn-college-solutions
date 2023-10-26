# import os

# exec("cd /challenge")
# exec("./embryoio_level22")

import subprocess
import os

with open('/tmp/phyzqu', 'rb') as f:
    subprocess.run(['/challenge/embryoio_level26'], stdin=f, check=True)
    
   
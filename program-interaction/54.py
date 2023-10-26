from subprocess import Popen, PIPE

process1 = Popen(["/challenge/embryoio_level54"], stdout=PIPE)
process2 = Popen(["cat"], stdin=process1.stdout)

process1.stdout.close()  # Allow process1 to receive a SIGPIPE if process2 exits.
process2.communicate()


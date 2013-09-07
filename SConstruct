env = Environment(tools = ['default', 'cxxtest'])
env.Append(CPPFLAGS=['-Wall','-g'])
Export('env')

#build external libraries
utils = env.SConscript('Components/Utils/SConscript' )
env.Prepend(LIBS=utils)

ooio = env.SConscript('Components/OO-IO/SConscript' )
env.Prepend(LIBS=ooio)

env.Program('DifferentialPressureSailObserver','main.cpp')
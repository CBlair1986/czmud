env = Environment(
        LIBS=['tcod', 'tcod++'],
        LIBPATH=['./libtcod-1.4.1', '.'],
        CPPPATH=['./libtcod-1.4.1/include', '.'])
main = env.Object('main.cpp')
globals = env.Object('globals.cpp')
region = env.Object('region.cpp')
player = env.Object('player.cpp')
nonplayer = env.Object('nonplayer.cpp')
input = env.Object('input.cpp')

objects = [main, globals, region, player, nonplayer, input]
env.Program('czgame', objects)
Clean(main,[Glob('*~'),Glob('*.swp'),'.sconsign.dblite','*~'])

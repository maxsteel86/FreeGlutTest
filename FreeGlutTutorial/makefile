GLUT=-lGL -lGLU -lglut
OUTDIR=out

all: CreateDir MakeInit MakeParticle MakeSceneBuilder MakeMain

MakeMain:
	g++ -Wall main2.cpp $(OUTDIR)/*.o $(GLUT) -o $(OUTDIR)/glutTut1

MakeParticle:
	make -C Particle
	mv Particle/*.o $(OUTDIR)

MakeSceneBuilder:
	make -C SceneBuilder
	mv SceneBuilder/*.o $(OUTDIR)

MakeInit:
	make -C GlutInit
	mv GlutInit/*.o $(OUTDIR)

CreateDir:
	mkdir -p $(OUTDIR)

clean:
	rm -rf $(OUTDIR)

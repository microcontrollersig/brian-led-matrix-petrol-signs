import Home from './routes/Home.svelte';
import ImageUpload from './routes/ImageUpload.svelte';
import ImageCreator from './routes/ImageCreator.svelte';
import Hangman from './routes/Hangman.svelte';
import Dino from './routes/Dino.svelte';
import RandomNumber from './routes/RandomNumber.svelte';
import TetrisTime from './routes/TetrisTime.svelte';

export default {
    '/': Home,
    '/imageupload': ImageUpload,
    '/imagecreator': ImageCreator,
    '/hangman': Hangman,
    '/dino': Dino,
    '/randomnumber': RandomNumber,
    '/tetristime': TetrisTime
};
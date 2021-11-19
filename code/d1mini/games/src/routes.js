import Home from './routes/Home.svelte';
import ImageUpload from './routes/ImageUpload.svelte';
import ImageCreator from './routes/ImageCreator.svelte';
import Hangman from './routes/Hangman.svelte';

export default {
    '/': Home,
    '/imageupload': ImageUpload,
    '/imagecreator': ImageCreator,
    '/hangman': Hangman
};
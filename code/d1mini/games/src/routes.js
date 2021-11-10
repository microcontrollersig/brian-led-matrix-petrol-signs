import Home from './routes/Home.svelte';
import ImageUpload from './routes/ImageUpload.svelte';

export default {
    '/': Home,
    '/imageupload': ImageUpload,
};